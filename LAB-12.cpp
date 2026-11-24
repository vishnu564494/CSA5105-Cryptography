
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[] = "meet me at the usual place at ten rather than eight oclock";
    char cipher[200], decrypted[200];

    int i, j = 0;
    int a, b, c, d;

    // Remove spaces
    for(i = 0; text[i] != '\0'; i++)
    {
        if(isalpha((unsigned char)text[i]))
            text[j++] = tolower((unsigned char)text[i]);
    }

    // Add padding
    if(j % 2 != 0)
        text[j++] = 'x';

    text[j] = '\0';

    printf("Plaintext: %s\n", text);

    // Encryption
    for(i = 0; i < j; i += 2)
    {
        a = text[i] - 'a';
        b = text[i+1] - 'a';

        c = (9*a + 4*b) % 26;
        d = (5*a + 7*b) % 26;

        cipher[i] = c + 'A';
        cipher[i+1] = d + 'A';
    }

    cipher[j] = '\0';

    printf("\nEncrypted text: %s\n", cipher);

    // Correct inverse key matrix
    for(i = 0; i < j; i += 2)
    {
        a = cipher[i] - 'A';
        b = cipher[i+1] - 'A';

        c = (5*a + 12*b) % 26;
        d = (15*a + 25*b) % 26;

        decrypted[i] = (c + 26) % 26 + 'a';
        decrypted[i+1] = (d + 26) % 26 + 'a';
    }

    decrypted[j] = '\0';

    printf("\nDecrypted text: %s\n", decrypted);

    return 0;
}

