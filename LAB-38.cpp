
#include <stdio.h>
#include <string.h>

int mod(int x)
{
    return (x % 26 + 26) % 26;
}

int inverse(int a)
{
    int i;
    for(i = 1; i < 26; i++)
        if((a * i) % 26 == 1)
            return i;
    return -1;
}

int main()
{
    char p[5], c[5];
    int a,b,d,e;
    int det, inv;
    int k[2][2];

    printf("Enter 4 plaintext letters: ");
    scanf("%4s", p);

    printf("Enter 4 ciphertext letters: ");
    scanf("%4s", c);

    int x1=p[0]-'A', x2=p[1]-'A';
    int x3=p[2]-'A', x4=p[3]-'A';

    int y1=c[0]-'A', y2=c[1]-'A';
    int y3=c[2]-'A', y4=c[3]-'A';

    // Plaintext matrix determinant
    det = mod(x1*x4 - x2*x3);
    inv = inverse(det);

    if(inv == -1)
    {
        printf("Attack not possible with these pairs.\n");
        return 0;
    }

    // Inverse of plaintext matrix
    a = mod(inv*x4);
    b = mod(-inv*x2);
    d = mod(-inv*x3);
    e = mod(inv*x1);

    // Recover encryption key
    k[0][0] = mod(y1*a + y3*b);
    k[0][1] = mod(y1*d + y3*e);
    k[1][0] = mod(y2*a + y4*b);
    k[1][1] = mod(y2*d + y4*e);

    printf("\nRecovered Hill Cipher Key:\n");
    printf("%d %d\n", k[0][0], k[0][1]);
    printf("%d %d\n", k[1][0], k[1][1]);

    return 0;
}

