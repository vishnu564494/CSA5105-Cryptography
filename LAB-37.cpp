
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char cipher[1000];
    char plain[1000];
    int i, j, shift;

    printf("Enter encrypted text:\n");
    fgets(cipher, sizeof(cipher), stdin);

    printf("\nTop 10 possible plaintexts:\n");

    for(shift = 1; shift <= 10; shift++)
    {
        for(i = 0; cipher[i] != '\0'; i++)
        {
            if(isalpha((unsigned char)cipher[i]))
            {
                char c = toupper((unsigned char)cipher[i]);
                char p = (c - 'A' - shift + 26) % 26 + 'A';

                plain[i] = islower((unsigned char)cipher[i])
                           ? tolower(p) : p;
            }
            else
            {
                plain[i] = cipher[i];
            }
        }

        plain[i] = '\0';

        printf("%d. %s", shift, plain);
    }

    return 0;
}

