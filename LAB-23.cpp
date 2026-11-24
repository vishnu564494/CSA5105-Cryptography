#include <stdio.h>

void printBinary(int n)
{
    int i;
    for(i = 7; i >= 0; i--)
        printf("%d", (n >> i) & 1);
}

int main()
{
    int plain[] = {1, 2, 4};
    int cipher[3], decrypt[3];
    int i, key = 40;

    printf("CTR ENCRYPTION\n");
    printf("Plaintext : ");

    for(i = 0; i < 3; i++)
    {
        printBinary(plain[i]);
        printf(" ");
    }

    for(i = 0; i < 3; i++)
    {
        cipher[i] = plain[i] ^ (key + i * 15);
    }

    printf("\nCiphertext: ");

    for(i = 0; i < 3; i++)
    {
        printBinary(cipher[i]);
        printf(" ");
    }

    for(i = 0; i < 3; i++)
    {
        decrypt[i] = cipher[i] ^ (key + i * 15);
    }

    printf("\n\nCTR DECRYPTION\n");
    printf("Plaintext : ");

    for(i = 0; i < 3; i++)
    {
        printBinary(decrypt[i]);
        printf(" ");
    }

    return 0;
}
