
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char cipher[500];
    char plain[500];
    int shift, i, j, n;

    printf("Enter ciphertext: ");
    fgets(cipher, sizeof(cipher), stdin);

    printf("Enter number of possible plaintexts: ");
    scanf("%d", &n);

    if(n < 1) n = 1;
    if(n > 26) n = 26;

    printf("\nPossible Plaintexts:\n");

    // Try all 26 possible shifts
    for(shift = 0; shift < n; shift++)
    {
        for(i = 0; cipher[i] != '\0'; i++)
        {
            if(isupper((unsigned char)cipher[i]))
                plain[i] = (cipher[i] - 'A' - shift + 26) % 26 + 'A';

            else if(islower((unsigned char)cipher[i]))
                plain[i] = (cipher[i] - 'a' - shift + 26) % 26 + 'a';

            else
                plain[i] = cipher[i];
        }

        plain[i] = '\0';

        printf("\nShift %d: %s", shift, plain);
    }

    return 0;
}

