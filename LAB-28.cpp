
#include <stdio.h>

int main()
{
    int q, a, x, y;
    int A, B, key1, key2;

    printf("Enter public prime number q: ");
    scanf("%d", &q);

    printf("Enter public number a: ");
    scanf("%d", &a);

    printf("Enter Alice secret number x: ");
    scanf("%d", &x);

    printf("Enter Bob secret number y: ");
    scanf("%d", &y);

    // Alice and Bob calculate public values
    A = 1;
    B = 1;

    for(int i = 0; i < x; i++)
        A = (A * a) % q;

    for(int i = 0; i < y; i++)
        B = (B * a) % q;

    printf("\nAlice sends: %d", A);
    printf("\nBob sends: %d", B);

    // Calculate shared secret key
    key1 = 1;
    key2 = 1;

    for(int i = 0; i < x; i++)
        key1 = (key1 * B) % q;

    for(int i = 0; i < y; i++)
        key2 = (key2 * A) % q;

    printf("\n\nAlice shared key: %d", key1);
    printf("\nBob shared key: %d", key2);

    if(key1 == key2)
        printf("\nKey Exchange Successful!");

    return 0;
}

