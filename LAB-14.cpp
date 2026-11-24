
#include <stdio.h>

int main()
{
    char p[] = "SENDMOREMONEY";
    char c[14];
    char required[] = "CASHNOTNEEDED";

    int key[13] = {9,0,1,7,23,15,21,14,11,11,2,8,9};
    int newkey[13];
    int i;

    // Encryption
    for(i = 0; i < 13; i++)
        c[i] = (p[i] - 'A' + key[i]) % 26 + 'A';

    c[13] = '\0';

    printf("Encrypted Text: ");
    for(i = 0; i < 13; i++)
    {
        printf("%c", c[i]);
        if(i == 3 || i == 7) printf(" ");
    }

    // Calculate new key
    for(i = 0; i < 13; i++)
        newkey[i] = (c[i] - required[i] + 26) % 26;

    printf("\n\nNew Key Stream: ");
    for(i = 0; i < 13; i++)
        printf("%d ", newkey[i]);

    // Decryption using new key
    printf("\n\nDecrypted Text: ");
    for(i = 0; i < 13; i++)
    {
        int value = (c[i] - 'A' - newkey[i] + 26) % 26;
        printf("%c", value + 'A');
    }

    printf("\n");

    return 0;
}

