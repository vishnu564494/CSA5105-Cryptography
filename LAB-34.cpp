
#include <stdio.h>
#include <string.h>

#define SIZE 8

void ECB(char *plain, char *key, char *cipher, int n)
{
    int i;
    for(i = 0; i < n; i++)
        cipher[i] = plain[i] ^ key[i % SIZE];
}

void CBC(char *plain, char *key, char *cipher, int n)
{
    int i;
    char iv = 'A';

    for(i = 0; i < n; i++)
    {
        cipher[i] = plain[i] ^ key[i % SIZE] ^ iv;
        iv = cipher[i];
    }
}

void CFB(char *plain, char *key, char *cipher, int n)
{
    int i;
    char iv = 'A';

    for(i = 0; i < n; i++)
    {
        char temp = iv ^ key[i % SIZE];
        cipher[i] = plain[i] ^ temp;
        iv = cipher[i];
    }
}

int main()
{
    char plain[100];
    char key[] = "12345678";
    char ecb[100], cbc[100], cfb[100];
    int n, i;

    printf("Enter plaintext: ");
    fgets(plain, sizeof(plain), stdin);

    n = strlen(plain);

    if(n > 0 && plain[n-1] == '\n')
        plain[--n] = '\0';

    if(n == 0)
    {
        printf("Plaintext cannot be empty");
        return 0;
    }

    ECB(plain, key, ecb, n);
    CBC(plain, key, cbc, n);
    CFB(plain, key, cfb, n);

    printf("\nECB Encryption: ");
    for(i = 0; i < n; i++)
        printf("%02X ", (unsigned char)ecb[i]);

    printf("\nCBC Encryption: ");
    for(i = 0; i < n; i++)
        printf("%02X ", (unsigned char)cbc[i]);

    printf("\nCFB Encryption: ");
    for(i = 0; i < n; i++)
        printf("%02X ", (unsigned char)cfb[i]);

    return 0;
}

