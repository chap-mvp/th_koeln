#include <stdio.h>

unsigned char manipulateByte(unsigned char byte)
{
    // Shift left by 2 bits
    unsigned char shifted = byte << 2;

    // Apply mask 0b01010101 (0x55)
    unsigned char result = shifted & 0b01010101;

    return result;
}

int main(void)
{
    unsigned char testByte = 0b00110011; // 51 decimal

    printf("Original: 0b");
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (testByte >> i) & 1);
    }
    printf(" (%d)\n", testByte);

    unsigned char result = manipulateByte(testByte);

    printf("Result:   0b");
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (result >> i) & 1);
    }
    printf(" (%d)\n", result);

    // Step by step explanation
    printf("\nStep-by-step:\n");
    printf("1. Original:        0b00110011\n");
    printf("2. Shifted left 2:  0b11001100\n");
    printf("3. Mask:            0b01010101\n");
    printf("4. Result (AND):    0b01000100\n");

    return 0;
}