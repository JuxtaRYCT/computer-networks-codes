#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main()
{
    int sock;
    struct sockaddr_in serv_addr;

    char buffer[1024] = {0};

    sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    inet_pton(AF_INET, "127.0.01", &serv_addr.sin_addr);
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    while (1)
    {
        printf("Enter message: ");
        fgets(buffer, 1024, stdin);
        send(sock, buffer, strlen(buffer), 0);
        read(sock, buffer, 1024);
        printf("Server: %s", buffer);
    }

    close(sock);
    return 0;
}