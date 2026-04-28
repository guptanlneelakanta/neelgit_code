#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

int main() {
    int server_fd, client_socket;
    sockaddr_in address{};
    char buffer[1024] = {0};
    socklen_t addrlen = sizeof(address);

    // 1. Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("socket failed");
        return 1;
    }

    // 2. Bind
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;   // accept any IP
    address.sin_port = htons(8080);

    if (bind(server_fd, (sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind failed");
        return 1;
    }

    // 3. Listen
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        return 1;
    }

    cout << "Server listening on port 8080...\n";

    // 4. Accept connection
    client_socket = accept(server_fd, (sockaddr*)&address, &addrlen);
    if (client_socket < 0) {
        perror("accept");
        return 1;
    }

    // 5. Read from client
    read(client_socket, buffer, 1024);
    cout << "Client says: " << buffer << endl;

    // 6. Send reply
    const char* msg = "Hello from server data: 123";
    send(client_socket, msg, strlen(msg), 0);

    close(client_socket);
    close(server_fd);
    return 0;
}


