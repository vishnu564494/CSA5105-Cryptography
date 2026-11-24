
#include <stdio.h>
#include <string.h>

#define BLOCK 4
#define KEY 9
#define IV 6

int sbox[16] = {
    14, 4, 13, 1, 2, 15, 11, 8,
    3, 10, 6, 12, 5, 9, 0, 7
};

// Simple 4-bit encryption function
int encrypt(int x)
{
    return sbox[x ^ KEY];
}

int main()
{
    char plain[110];
    int P[30], ECB[30], CBC[30], CFB[30];
    int n, blocks, i, j;
    int previous, reg, c;

    printf("Enter plaintext (0 and 1 only): ");
    scanf("%109s", plain);

    n = strlen(plain);

    // Validate input
    for(i = 0; i < n; i++)
    {
        if(plain[i] != '0' && plain[i] != '1')
        {
            printf("Invalid input!");
            return 0;
        }
    }

    // Add padding
    plain[n++] = '1';

    while(n % BLOCK != 0)
        plain[n++] = '0';

    plain[n] = '\0';

    printf("\nPadded Plaintext: %s\n", plain);

    blocks = n / BLOCK;

    // Convert binary into 4-bit blocks
    for(i = 0; i < blocks; i++)
    {
        P[i] = 0;

        for(j = 0; j < BLOCK; j++)
            P[i] = P[i] * 2 + (plain[i*BLOCK+j] - '0');
    }

    // ECB MODE
    for(i = 0; i < blocks; i++)
        ECB[i] = encrypt(P[i]);

    // CBC MODE
    previous = IV;

    for(i = 0; i < blocks; i++)
    {
        CBC[i] = encrypt(P[i] ^ previous);
        previous = CBC[i];
    }

    // CFB MODE (4-bit segments)
    reg = IV;

    for(i = 0; i < blocks; i++)
    {
        c = encrypt(reg);
        CFB[i] = P[i] ^ c;
        reg = CFB[i];
    }

    // Display ECB output
    printf("\nECB Output: ");
    for(i = 0; i < blocks; i++)
        printf("%04d", 0); // Placeholder replaced below

    // Display binary values
    printf("\rECB Output: ");
    for(i = 0; i < blocks; i++)
    {
        for(j = 3; j >= 0; j--)
            printf("%d", (ECB[i] >> j) & 1);
    }

    printf("\nCBC Output: ");
    for(i = 0; i < blocks; i++)
    {
        for(j = 3; j >= 0; j--)
            printf("%d", (CBC[i] >> j) & 1);
    }

    printf("\nCFB Output: ");
    for(i = 0; i < blocks; i++)
    {
        for(j = 3; j >= 0; j--)
            printf("%d", (CFB[i] >> j) & 1);
    }

    printf("\n");

    return 0;
}

