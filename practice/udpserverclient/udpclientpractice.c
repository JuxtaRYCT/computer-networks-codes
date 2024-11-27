#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main()
{
    int sockfd;
    struct sockaddr_in listen_addr;
    char buffer[1024] = {0};

    socklen_t addr_len = sizeof(listen_addr);
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(PORT);
    listen_addr.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd, (struct sockaddr *)&listen_addr, sizeof(listen_addr));

    while (1)
    {
        recvfrom(sockfd, buffer, 1024, 0, (struct sockaddr *)&listen_addr, &addr_len);
        printf("Received: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}