#include <stdio.h>

int calculateEvenParity(unsigned char data) {
    int parity = 0;
    for (int i = 0; i < 8; i++) {
        if (data & (1 << i)) {
            parity = !parity;
        }
    }
    return parity;
}

int main() {
    unsigned char data, receivedData;
    int transmittedParity, receivedParity;

    printf("Enter 8-bit data (0-255): ");
    scanf("%hhu", &data);

    transmittedParity = calculateEvenParity(data);

    printf("Transmitted Data: %d (Binary: ", data);
    for (int i = 7; i >= 0; i--) {
        printf("%d", (data >> i) & 1);
    }
    printf(") with Even Parity: %d\n", transmittedParity);

    printf("Enter received 8-bit data (0-255): ");
    scanf("%hhu", &receivedData);

    receivedParity = calculateEvenParity(receivedData);

    printf("Received Data: %d (Binary: ", receivedData);
    for (int i = 7; i >= 0; i--) {
        printf("%d", (receivedData >> i) & 1);
    }
    printf(") with Even Parity: %d\n", receivedParity);

    if (transmittedParity == receivedParity) {
        printf("Data received correctly.\n");
    } else {
        printf("Data received incorrectly.\n");
    }

    return 0;
}
