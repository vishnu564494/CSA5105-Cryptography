
#include <stdio.h>

int main()
{
    int p = 23, q = 11;
    int g = 4, x = 3;
    int h = 5, k1 = 2, k2 = 7;
    int s1, s2, r1, r2;

    // DSA signature demonstration
    r1 = (g * k1) % q;
    s1 = ((h + x * r1) * 6) % q;

    r2 = (g * k2) % q;
    s2 = ((h + x * r2) * 8) % q;

    printf("DSA Signatures:\n");
    printf("First Signature  : (%d, %d)\n", r1, s1);
    printf("Second Signature : (%d, %d)\n", r2, s2);

    // RSA signature demonstration
    int n = 33, d = 7, m = 4;
    int rsa1 = 1, rsa2 = 1;

    for(int i = 0; i < d; i++)
    {
        rsa1 = (rsa1 * m) % n;
        rsa2 = (rsa2 * m) % n;
    }

    printf("\nRSA Signatures:\n");
    printf("First Signature  : %d\n", rsa1);
    printf("Second Signature : %d\n", rsa2);

    return 0;
}

