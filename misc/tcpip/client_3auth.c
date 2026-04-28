#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

void simple_hash(char *input, char *output) {
    int sum = 0;
    for(int i = 0; i < strlen(input); i++)
        sum += input[i];
    sprintf(output, "%d", sum);
}

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;

    char username[50], password[50];
    char challenge[50], hash[50];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    // STEP 1: Send username
    printf("Enter username: ");
    scanf("%s", username);
    send(sock, username, strlen(username), 0);

    // STEP 2: Receive challenge
    read(sock, challenge, sizeof(challenge));
    printf("Challenge: %s\n", challenge);

    // STEP 3: Send hashed response
    printf("Enter password: ");
    scanf("%s", password);

    char combined[100];
    sprintf(combined, "%s%s", password, challenge);

    simple_hash(combined, hash);
    send(sock, hash, strlen(hash), 0);

    // Final response
    char buffer[100];
    read(sock, buffer, sizeof(buffer));
    printf("Server: %s\n", buffer);

    close(sock);
    return 0;
}