
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX 2000
#define TRIES 30000

char cipher[MAX], bestText[MAX];
char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

double freq[26] = {
    8.167, 1.492, 2.782, 4.253, 12.702, 2.228,
    2.015, 6.094, 6.966, 0.153, 0.772, 4.025,
    2.406, 6.749, 7.507, 1.929, 0.095, 5.987,
    6.327, 9.056, 2.758, 0.978, 2.360, 0.150,
    1.974, 0.074
};

void decrypt(char key[], char output[])
{
    int i;

    for(i = 0; cipher[i] != '\0'; i++)
    {
        if(isalpha((unsigned char)cipher[i]))
        {
            int x = toupper((unsigned char)cipher[i]) - 'A';
            char ch = key[x];

            output[i] = islower((unsigned char)cipher[i])
                        ? tolower((unsigned char)ch) : ch;
        }
        else
            output[i] = cipher[i];
    }

    output[i] = '\0';
}

double score(char key[])
{
    int count[26] = {0};
    int total = 0, i, x;
    double result = 0;
    char text[MAX];

    decrypt(key, text);

    for(i = 0; text[i] != '\0'; i++)
    {
        if(isalpha((unsigned char)text[i]))
        {
            x = toupper((unsigned char)text[i]) - 'A';
            count[x]++;
            total++;
        }
    }

    if(total == 0)
        return -100000;

    for(i = 0; i < 26; i++)
    {
        double expected = freq[i] / 100.0;
        double actual = (double)count[i] / total;
        result -= (actual - expected) *
                  (actual - expected) / (expected + 0.001);
    }

    return result;
}

void randomKey(char key[])
{
    int i, j;
    char temp;

    for(i = 0; i < 26; i++)
        key[i] = 'A' + i;

    for(i = 25; i > 0; i--)
    {
        j = rand() % (i + 1);
        temp = key[i];
        key[i] = key[j];
        key[j] = temp;
    }
}

int main()
{
    char key[26], newKey[26];
    char output[MAX];
    int top, i, j, a, b;
    double current, next;

    srand((unsigned)time(NULL));

    printf("Enter ciphertext: ");
    fgets(cipher, MAX, stdin);

    printf("Enter number of possible plaintexts: ");
    scanf("%d", &top);

    if(top < 1) top = 1;
    if(top > 10) top = 10;

    printf("\nPossible Plaintexts:\n");

    for(i = 0; i < top; i++)
    {
        randomKey(key);
        current = score(key);

        for(j = 0; j < TRIES; j++)
        {
            memcpy(newKey, key, 26);

            a = rand() % 26;
            b = rand() % 26;

            char temp = newKey[a];
            newKey[a] = newKey[b];
            newKey[b] = temp;

            next = score(newKey);

            if(next > current ||
               (double)rand() / RAND_MAX < 0.01)
            {
                memcpy(key, newKey, 26);
                current = next;
            }
        }

        decrypt(key, output);

        printf("%d. %s\n\n", i + 1, output);
    }

    return 0;
}

