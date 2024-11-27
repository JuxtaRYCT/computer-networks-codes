#include <stdio.h>
// Function to calculate the parity bits
void calculateHamming(int data[], int hammingCode[])
{
    // Data bits
    hammingCode[2] = data[0];
    hammingCode[4] = data[1];
    hammingCode[5] = data[2];
    hammingCode[6] = data[3];
    // Parity bits
    hammingCode[0] = hammingCode[2] ^ hammingCode[4] ^ hammingCode[6];
    hammingCode[1] = hammingCode[2] ^ hammingCode[5] ^ hammingCode[6];
    hammingCode[3] = hammingCode[4] ^ hammingCode[5] ^ hammingCode[6];
} // Function to check and correct errors
int checkHamming(int hammingCode[])
{
    int c1 = hammingCode[0] ^ hammingCode[2] ^ hammingCode[4] ^ hammingCode[6];
    int c2 = hammingCode[1] ^ hammingCode[2] ^ hammingCode[5] ^ hammingCode[6];
    int c4 = hammingCode[3] ^ hammingCode[4] ^ hammingCode[5] ^ hammingCode[6];
    int errorPos = c1 + (c2 * 2) + (c4 * 4);
    return errorPos;
}
int main()
{
    int data[] = {1, 0, 1, 1}; // 4-bit data
    int hammingCode[7];
    // Generate Hamming Code
    calculateHamming(data, hammingCode);
    // Print Hamming Code
    printf("Hamming Code: ");
    for (int i = 0; i < 7; i++)
    {
        printf("%d", hammingCode[i]);
    }
    printf("\n");
    // Simulate a single-bit error in transmission
    hammingCode[2] = 0; // Intentionally flipping a bit
    // Detect and correct error
    int errorPos = checkHamming(hammingCode);
    if (errorPos == 0)
    {
        printf("No error detected.\n");
    }
    else
    {
        printf("Error detected at position: %d\n", errorPos);
        hammingCode[errorPos - 1] = !hammingCode[errorPos - 1];
        printf("Corrected Hamming Code: ");
        for (int i = 0; i < 7; i++)
        {
            printf("%d", hammingCode[i]);
        }
        printf("\n");
    }
    return 0;
}