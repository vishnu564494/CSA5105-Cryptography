
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char pt[100], ct[100], dt[100];
    int key[100], i, n;

    printf("Enter plaintext: ");
    scanf("%s", pt);

    n = strlen(pt);

    printf("Enter %d key values (0-25):\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &key[i]);
    }

    // Encryption
    for(i = 0; i < n; i++)
    {
        ct[i] = ((toupper(pt[i]) - 'A' + key[i]) % 26) + 'A';
    }
    ct[i] = '\0';

    // Decryption
    for(i = 0; i < n; i++)
    {
        dt[i] = ((ct[i] - 'A' - key[i] + 26) % 26) + 'A';
    }
    dt[i] = '\0';

    printf("\nEncrypted text: %s", ct);
    printf("\nDecrypted text: %s\n", dt);

    return 0;
}

