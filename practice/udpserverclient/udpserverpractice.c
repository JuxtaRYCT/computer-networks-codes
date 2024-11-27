#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main()
{
    int sockfd;
    struct sockaddr_in broadcast_addr;
    char message[] = "Broadcast message from server";

    // Create socket
    // sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    // if (sockfd < 0)
    // {
    //     perror("Socket creation failed");
    //     exit(EXIT_FAILURE);
    // }

    // // Enable broadcast option
    // int broadcastEnable = 1;
    // if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &broadcastEnable, sizeof(broadcastEnable)) < 0)
    // {
    //     perror("Error setting broadcast option");
    //     close(sockfd);
    //     exit(EXIT_FAILURE);
    // }

    // Configure broadcast address
    broadcast_addr.sin_family = AF_INET;
    broadcast_addr.sin_port = htons(PORT);
    broadcast_addr.sin_addr.s_addr = inet_addr("255.255.255.255");

    // Broadcast messages in a loop
    while (1)
    {
        sendto(sockfd, message, strlen(message), 0, (struct sockaddr *)&broadcast_addr, sizeof(broadcast_addr));
        printf("Broadcasted: %s\n", message);
        sleep(1);
    }

    close(sockfd);
    return 0;
}