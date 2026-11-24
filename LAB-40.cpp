
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

// English letter frequency order
char english[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";

int main()
{
    char cipher[MAX], temp[MAX];
    int freq[26] = {0};
    int i, j, top, count = 0;
    char letters[26];

    printf("Enter encrypted text:\n");
    fgets(cipher, MAX, stdin);

    printf("Enter number of possible plaintexts: ");
    scanf("%d", &top);

    if(top < 1) top = 1;
    if(top > 10) top = 10;

    // Count letter frequencies
    for(i = 0; cipher[i] != '\0'; i++)
    {
        if(isalpha((unsigned char)cipher[i]))
            freq[toupper((unsigned char)cipher[i]) - 'A']++;
    }

    // Sort letters by frequency
    for(i = 0; i < 26; i++)
        letters[i] = 'A' + i;

    for(i = 0; i < 26; i++)
    {
        for(j = i + 1; j < 26; j++)
        {
            if(freq[letters[j]-'A'] >
               freq[letters[i]-'A'])
            {
                char t = letters[i];
                letters[i] = letters[j];
                letters[j] = t;
            }
        }
    }

    printf("\nTop %d possible plaintexts:\n", top);

    // Generate possible plaintexts
    for(count = 0; count < top; count++)
    {
        int shift = count;
        char key[26];

        for(i = 0; i < 26; i++)
            key[letters[i]-'A'] = english[(i+shift)%26];

        strcpy(temp, cipher);

        for(i = 0; temp[i] != '\0'; i++)
        {
            if(isalpha((unsigned char)temp[i]))
            {
                int index = toupper((unsigned char)temp[i])-'A';
                char ch = key[index];

                temp[i] = islower((unsigned char)temp[i])
                          ? tolower(ch) : ch;
            }
        }

        printf("%d. %s", count+1, temp);
    }

    return 0;
}

