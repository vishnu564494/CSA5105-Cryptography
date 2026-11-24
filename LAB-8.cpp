
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char plain[100], cipher[100];
    char key[] = "CIPHER";
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char map[27];
    int i, j, k = 0, found;

    // Generate cipher sequence using keyword
    for(i = 0; key[i] != '\0'; i++)
    {
        found = 0;

        for(j = 0; j < k; j++)
        {
            if(map[j] == key[i])
            {
                found = 1;
                break;
            }
        }

        if(!found)
            map[k++] = key[i];
    }

    // Add remaining unused letters
    for(i = 0; i < 26; i++)
    {
        found = 0;

        for(j = 0; j < k; j++)
        {
            if(map[j] == alphabet[i])
            {
                found = 1;
                break;
            }
        }

        if(!found)
            map[k++] = alphabet[i];
    }

    map[26] = '\0';

    printf("Plain Alphabet : %s\n", alphabet);
    printf("Cipher Alphabet: %s\n", map);

    printf("\nEnter Plain Text: ");
    fgets(plain, sizeof(plain), stdin);

    // Encryption
    printf("\nEncrypted Text: ");

    for(i = 0; plain[i] != '\0'; i++)
    {
        if(isalpha((unsigned char)plain[i]))
        {
            char ch = toupper((unsigned char)plain[i]);
            printf("%c", map[ch - 'A']);
        }
        else
        {
            printf("%c", plain[i]);
        }
    }

    // Decryption
    printf("\nEnter Cipher Text: ");
    fgets(cipher, sizeof(cipher), stdin);

    printf("\nDecrypted Text: ");

    for(i = 0; cipher[i] != '\0'; i++)
    {
        if(isalpha((unsigned char)cipher[i]))
        {
            char ch = toupper((unsigned char)cipher[i]);

            for(j = 0; j < 26; j++)
            {
                if(map[j] == ch)
                {
                    printf("%c", alphabet[j]);
                    break;
                }
            }
        }
        else
        {
            printf("%c", cipher[i]);
        }
    }

    return 0;
}

