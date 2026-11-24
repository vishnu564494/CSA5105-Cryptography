
#include <stdio.h>
#include <stdint.h>

void leftShift(uint8_t *in, uint8_t *out, int n)
{
    int i;
    uint8_t carry = 0;

    for (i = n - 1; i >= 0; i--)
    {
        uint8_t next = (in[i] >> 7) & 1;
        out[i] = (in[i] << 1) | carry;
        carry = next;
    }
}

void generateSubkey(uint8_t *in, uint8_t *out,
                    int n, uint8_t R)
{
    leftShift(in, out, n);

    if (in[0] & 0x80)
        out[n - 1] ^= R;
}

void printKey(uint8_t *key, int n)
{
    for (int i = 0; i < n; i++)
        printf("%02X ", key[i]);
    printf("\n");
}

int main()
{
    uint8_t L[16] = {0};
    uint8_t K1[16], K2[16];

    int n, bits;
    uint8_t R;

    printf("Enter block size (64 or 128): ");
    scanf("%d", &bits);

    if (bits == 64)
    {
        n = 8;
        R = 0x1B;
    }
    else if (bits == 128)
    {
        n = 16;
        R = 0x87;
    }
    else
    {
        printf("Invalid block size");
        return 0;
    }

    printf("Enter L in hexadecimal (%d bytes): ", n);
    for (int i = 0; i < n; i++)
        scanf("%2hhx", &L[i]);

    generateSubkey(L, K1, n, R);
    generateSubkey(K1, K2, n, R);

    printf("\nFirst Subkey K1: ");
    printKey(K1, n);

    printf("Second Subkey K2: ");
    printKey(K2, n);

    return 0;
}

