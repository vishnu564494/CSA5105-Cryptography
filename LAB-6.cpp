
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int modInverse(int a)
{
    int i;
    for(i = 1; i < 26; i++)
    {
        if((a * i) % 26 == 1)
            return i;
    }
    return -1;
}

int main()
{
    char cipher[1000];
    int a, b, inv, i;
    int x, y;

    printf("Enter Ciphertext: ");
    fgets(cipher, sizeof(cipher), stdin);

    // B represents E and U represents T
    // Find possible affine key values

    for(a = 1; a < 26; a++)
    {
        inv = modInverse(a);

        if(inv == -1)
            continue;

        for(b = 0; b < 26; b++)
        {
            // B = 1 maps to E = 4
            // U = 20 maps to T = 19

            if((a * 4 + b) % 26 == 1 &&
               (a * 19 + b) % 26 == 20)
            {
                printf("\nPossible Key: a = %d, b = %d\n",
                       a, b);

                printf("Decrypted Text: ");

                for(i = 0; cipher[i] != '\0'; i++)
                {
                    if(isupper(cipher[i]))
                    {
                        x = cipher[i] - 'A';
                        y = (inv * (x - b + 26)) % 26;
                        printf("%c", y + 'A');
                    }
                    else if(islower(cipher[i]))
                    {
                        x = cipher[i] - 'a';
                        y = (inv * (x - b + 26)) % 26;
                        printf("%c", y + 'a');
                    }
                    else
                    {
                        printf("%c", cipher[i]);
                    }
                }
                printf("\n");
            }
        }
    }

    return 0;
}

