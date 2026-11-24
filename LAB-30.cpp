
#include <stdio.h>

int main()
{
    int K, X, T;
    int block1, block2;
    int mac1, mac2;

    printf("Enter key K: ");
    scanf("%d", &K);

    printf("Enter message block X: ");
    scanf("%d", &X);

    // One-block CBC-MAC
    T = X ^ K;

    printf("\nCBC-MAC of one-block message");
    printf("\nT = %d", T);

    // Two-block message: X || (X XOR T)
    block1 = X;
    block2 = X ^ T;

    mac1 = block1 ^ K;
    mac2 = (mac1 ^ block2) ^ K;

    printf("\n\nTwo-block message");
    printf("\nBlock 1: %d", block1);
    printf("\nBlock 2: %d", block2);
    printf("\nCBC-MAC: %d", mac2);

    if(mac1 == mac2)
        printf("\n\nCBC-MAC values are equal!");

    return 0;
}

