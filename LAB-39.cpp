
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char cipher[1000], plain[1000];
    int freq[26] = {0};
    int shift, i, j, top;

    printf("Enter encrypted text:\n");
    fgets(cipher, sizeof(cipher), stdin);

    printf("Enter number of possible plaintexts: ");
    scanf("%d", &top);

    if(top < 1 || top > 26)
        top = 10;

    // Count letter frequencies
    for(i = 0; cipher[i] != '\0'; i++)
    {
        if(isalpha(cipher[i]))
            freq[toupper(cipher[i]) - 'A']++;
    }

    // Try all 26 possible shifts
    printf("\nTop %d Possible Plaintexts:\n", top);

    for(j = 0; j < top; j++)
    {
        int best = -1;
        int bestFreq = -1;

        // Select most frequent remaining letter
        for(i = 0; i < 26; i++)
        {
            if(freq[i] > bestFreq)
            {
                bestFreq = freq[i];
                best = i;
            }
        }

        // Choose a shift based on common English letter E
        shift = (best - 4 + 26) % 26;

        printf("\n%d. ", j + 1);

        for(i = 0; cipher[i] != '\0'; i++)
        {
            if(isupper(cipher[i]))
                putchar((cipher[i] - 'A' - shift + 26) % 26 + 'A');
            else if(islower(cipher[i]))
                putchar((cipher[i] - 'a' - shift + 26) % 26 + 'a');
            else
                putchar(cipher[i]);
        }

        // Remove selected frequency
        freq[best] = -1;
    }

    return 0;
}

