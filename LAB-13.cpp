
#include <stdio.h>

int main()
{
    int p[2][2] = {{1,0},{0,1}};
    int c[2][2];
    int key[2][2];
    int k[2][2] = {{9,4},{5,7}};
    int i, j, x;

    printf("HILL CIPHER - CHOSEN PLAINTEXT ATTACK\n");

    printf("\nChosen Plaintext Matrix:\n");
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
            printf("%d ", p[i][j]);
        printf("\n");
    }

    // Encryption
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            c[i][j] = 0;

            for(x = 0; x < 2; x++)
                c[i][j] += k[i][x] * p[x][j];

            c[i][j] %= 26;
        }
    }

    printf("\nCorresponding Ciphertext Matrix:\n");
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }

    // Recover key
    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
            key[i][j] = c[i][j];

    printf("\nRecovered Hill Cipher Key:\n");
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
            printf("%d ", key[i][j]);
        printf("\n");
    }

    return 0;
}

