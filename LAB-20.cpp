
#include <stdio.h>

int main()
{
    int P[4] = {10, 20, 30, 40};
    int C[4], D[4];
    int key = 5, iv = 7;
    int i;

    printf("ECB MODE\n");

    for(i = 0; i < 4; i++)
        C[i] = P[i] ^ key;

    C[1] = C[1] ^ 1;  // Error in second block

    for(i = 0; i < 4; i++)
        D[i] = C[i] ^ key;

    printf("Received plaintext: ");
    for(i = 0; i < 4; i++)
        printf("%d ", D[i]);

    printf("\n\nCBC MODE\n");

    for(i = 0; i < 4; i++)
    {
        C[i] = P[i] ^ iv ^ key;
        iv = C[i];
    }

    C[0] = C[0] ^ 1;  // Error in first block

    iv = 7;

    for(i = 0; i < 4; i++)
    {
        D[i] = C[i] ^ key ^ iv;
        iv = C[i];
    }

    printf("Received plaintext: ");
    for(i = 0; i < 4; i++)
        printf("%d ", D[i]);

    return 0;
}

