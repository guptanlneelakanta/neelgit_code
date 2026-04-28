#include <openssl/ssl.h>
#include <openssl/err.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

#define PORT 8443

void init_openssl()
{
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
}

SSL_CTX* create_context2()
{
    const SSL_METHOD* method = TLS_server_method();
    SSL_CTX* ctx = SSL_CTX_new(method);
    if (!ctx) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    return ctx;
}

SSL_CTX* create_context()
{
    const SSL_METHOD* method = TLS_server_method();
    SSL_CTX* ctx = SSL_CTX_new(method);
    if (!ctx) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    /* Enforce TLS 1.2+ */
  //  SSL_CTX_set_min_proto_version(ctx, TLS1_2_VERSION);
  
  /* Enforce TLS 1.2+ */
    SSL_CTX_set_min_proto_version(ctx, TLS1_2_VERSION);

    /* Ensure shared cipher availability */
    SSL_CTX_set_cipher_list(ctx, "HIGH:!aNULL:!MD5");

  

    return ctx;
}

void configure_context(SSL_CTX* ctx)
{
    SSL_CTX_use_certificate_file(ctx, "server.crt", SSL_FILETYPE_PEM);
    SSL_CTX_use_PrivateKey_file(ctx, "server.key", SSL_FILETYPE_PEM);
}

int main()
{
    init_openssl();
    SSL_CTX* ctx = create_context();
//    SSL_CTX_set_min_proto_version(ctx, TLS1_2_VERSION);

SSL_CTX_set_min_proto_version(ctx, TLS1_2_VERSION);

/* Allow common TLS 1.2 ciphers */
SSL_CTX_set_cipher_list(ctx, "HIGH:!aNULL:!MD5");

    configure_context(ctx);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd, (sockaddr*)&addr, sizeof(addr));
    listen(sockfd, 1);

    std::cout << "HTTPS Server listening on port " << PORT << std::endl;

    int client = accept(sockfd, nullptr, nullptr);

    SSL* ssl = SSL_new(ctx);
    SSL_set_fd(ssl, client);

//while(1)
//{
    if (SSL_accept(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
    } else {
    /*
    char buffer[1024] = {0};
    SSL_read(ssl, buffer, sizeof(buffer));

    std::cout << "data reved from client " << buffer << std::endl;
    
    const char* response =
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/plain\r\n"
    "Content-Length: 27\r\n\r\n"
    "Hello from HTTPS C++ Server test\n";

    SSL_write(ssl, response, strlen(response));

*/    
    char request[4096] = {0};
int r = SSL_read(ssl, request, sizeof(request) - 1);

if (r > 0) {
    std::cout << "Request received:\n" << request << std::endl;
}

const char* response =
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/html; charset=UTF-8\r\n"
    "Content-Length: 40\r\n"
    "Connection: close\r\n\r\n"
    "<html><body>Hello HTTPS</body></html>";

SSL_write(ssl, response, strlen(response));

    }
//}
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(client);
    close(sockfd);
    SSL_CTX_free(ctx);
    EVP_cleanup();
}

