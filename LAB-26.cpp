
#include <stdio.h>

int main()
{
    int p = 5, q = 11;
    int n, phi;
    int e1 = 3, d1 = 7;
    int e2 = 7, d2 = 3;

    n = p * q;
    phi = (p - 1) * (q - 1);

    printf("RSA KEY GENERATION\n");
    printf("p = %d\n", p);
    printf("q = %d\n", q);
    printf("n = %d\n", n);
    printf("Phi(n) = %d\n", phi);

    printf("\nOld Public Key: (%d, %d)\n", e1, n);
    printf("Old Private Key: (%d, %d)\n", d1, n);

    printf("\nBob's private key is leaked!\n");

    printf("\nNew Public Key: (%d, %d)\n", e2, n);
    printf("New Private Key: (%d, %d)\n", d2, n);

    printf("\nRSA SECURITY ANALYSIS\n");
    printf("Is generating new keys with same n safe? NO\n");
    printf("The attacker can calculate the new private key.\n");
    printf("A new modulus must be generated.\n");

    return 0;
}

