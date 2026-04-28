#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));

    // Listen
    listen(server_fd, 3);
    std::cout << "Server listening on port " << PORT << std::endl;

    // Accept connection
    new_socket = accept(server_fd, (struct sockaddr *)&address, 
                        (socklen_t*)&addrlen);

    // Read data
    read(new_socket, buffer, 1024);
    std::cout << "Client says: " << buffer << std::endl;

    // Send response
    const char *msg = "Hello from server";
    send(new_socket, msg, strlen(msg), 0);

    close(new_socket);
    close(server_fd);
    return 0;
}