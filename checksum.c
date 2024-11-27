#include <stdio.h>

unsigned char calculateChecksum(unsigned char frames[], int frameCount) {
    unsigned char checksum = 0;
    for (int i = 0; i < frameCount; i++) {
        checksum ^= frames[i];
    }
    return checksum;
}

int main() {
    int frameCount = 4;
    unsigned char frames[frameCount];
    unsigned char receivedFrames[frameCount];
    unsigned char checksum, receivedChecksum;

    printf("Enter %d frames of 8-bit data (in binary, e.g., 11001100):\n", frameCount);
    for (int i = 0; i < frameCount; i++) {
        printf("Frame %d: ", i + 1);
        unsigned int temp;
        scanf("%x", &temp);
        frames[i] = (unsigned char)temp;
    }

    checksum = calculateChecksum(frames, frameCount);

    printf("Calculated Checksum (in binary): ");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (checksum >> i) & 1);
    }
    printf("\n");

    printf("\nSimulating reception of data...\n");
    for (int i = 0; i < frameCount; i++) {
        printf("Received Frame %d: ", i + 1);
        unsigned int temp;
        scanf("%x", &temp);
        receivedFrames[i] = (unsigned char)temp;
    }

    receivedChecksum = calculateChecksum(receivedFrames, frameCount);

    printf("Received Checksum (in binary): ");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (receivedChecksum >> i) & 1);
    }
    printf("\n");

    if (checksum == receivedChecksum) {
        printf("No error detected. Data received correctly.\n");
    } else {
        printf("Error detected in received data.\n");
    }

    return 0;
}
