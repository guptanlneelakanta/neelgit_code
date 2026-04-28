#include <openssl/ssl.h>
#include <openssl/err.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>

#define PORT 8443

void init_openssl()
{
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
}

SSL_CTX* create_context()
{
    const SSL_METHOD* method = TLS_client_method();
    SSL_CTX* ctx = SSL_CTX_new(method);
    if (!ctx) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    return ctx;
}

int main()
{
    init_openssl();
    SSL_CTX* ctx = create_context();

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);

    connect(sockfd, (sockaddr*)&addr, sizeof(addr));

    SSL* ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);

    SSL_connect(ssl);

    const char* request =
        "GET / HTTP/1.1\r\n"
        "Host: localhost\r\n\r\n";
//while(1)
//{

    SSL_write(ssl, request, strlen(request));

    char buffer[1024]{};
    int bytes = SSL_read(ssl, buffer, sizeof(buffer));
    std::cout << buffer << std::endl;
//}
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sockfd);
    SSL_CTX_free(ctx);
    EVP_cleanup();
}

