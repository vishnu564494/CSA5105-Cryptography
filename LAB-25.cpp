
#include <stdio.h>

int main()
{
    int n, e, block, a, b, temp;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter public key e: ");
    scanf("%d", &e);

    printf("Enter plaintext block: ");
    scanf("%d", &block);

    a = block;
    b = n;

    // Find GCD
    while(b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }

    printf("\nRSA ANALYSIS\n");
    printf("n = %d\n", n);
    printf("Public key e = %d\n", e);
    printf("Plaintext block = %d\n", block);
    printf("GCD(block, n) = %d\n", a);

    if(a > 1)
    {
        printf("Common factor found!\n");
        printf("This helps to factorize n.\n");
    }
    else
    {
        printf("No common factor found.\n");
        printf("This does not help to factorize n.\n");
    }

    return 0;
}

