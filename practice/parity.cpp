#include <stdio.h>
// Function to calculate even parity for a byte
int calculateParity(int data[], int size)
{
    int parity = 0;
    for (int i = 0; i < size; i++)
    {
        parity ^= data[i];
    }
    return parity;
}
int main()
{
    int data[8];
    int size = 8;
    // Input 8-bit data from the user
    printf("Enter 8-bit data (1 or 0 for each bit):\n");
    for (int i = 0; i < size; i++)
    {
        printf("Bit %d: ", i + 1);
        scanf("%d", &data[i]);
    }
    // Calculate parity bit (for even parity)
    int parity = calculateParity(data, size);
    printf("Calculated Parity Bit (Even Parity): %d\n", parity);
    // Append the parity bit to the data for transmission
    int transmittedData[9];
    for (int i = 0; i < size; i++)
    {
        transmittedData[i] = data[i];
    }
    transmittedData[size] = parity;
    // Simulate reception and check parity at the receiver's end
    int receivedParity = calculateParity(transmittedData, size + 1);
    if (receivedParity == 0)
    {
        printf("No error detected. Data received correctly.\n");
    }
    else
    {
        printf("Error detected in the received data.\n");
    }
    return 0;
}