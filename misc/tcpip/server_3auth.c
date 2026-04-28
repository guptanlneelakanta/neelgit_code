#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080

// simple "hash" (for demo only)
void simple_hash(char *input, char *output) {
    int sum = 0;
    for(int i = 0; i < strlen(input); i++)
        sum += input[i];
    sprintf(output, "%d", sum);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    char username[50], challenge[50], client_hash[50];
    char expected_hash[50];

    char *stored_user = "admin";
    char *stored_pass = "1234";

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);

    printf("Server listening...\n");

    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);

    // STEP 1: Receive username
    read(new_socket, username, sizeof(username));
    printf("Username: %s\n", username);

    // STEP 2: Send challenge
    srand(time(NULL));
    sprintf(challenge, "%d", rand() % 10000);
    send(new_socket, challenge, strlen(challenge), 0);

    // STEP 3: Receive hashed response
    read(new_socket, client_hash, sizeof(client_hash));

    // Server computes expected hash
    char combined[100];
    sprintf(combined, "%s%s", stored_pass, challenge);
    simple_hash(combined, expected_hash);

    if(strcmp(username, stored_user) == 0 &&
       strcmp(client_hash, expected_hash) == 0) {
        send(new_socket, "AUTH_SUCCESS", 12, 0);
    } else {
        send(new_socket, "AUTH_FAIL", 9, 0);
    }

    close(new_socket);
    close(server_fd);
    return 0;
}