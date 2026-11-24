
#include <stdio.h>
#include <string.h>

int main()
{
    char text[100], key[100];
    int i;

    printf("Enter Plain Text: ");
    scanf("%s", text);

    printf("Enter Key: ");
    scanf("%s", key);

    printf("\nOriginal Text: %s", text);

    // Simple XOR demonstration
    for(i = 0; text[i] != '\0'; i++)
        text[i] = text[i] ^ key[i % strlen(key)];

    printf("\nEncrypted Text: ");
    for(i = 0; text[i] != '\0'; i++)
        printf("%02X ", (unsigned char)text[i]);

    // Decryption
    for(i = 0; text[i] != '\0'; i++)
        text[i] = text[i] ^ key[i % strlen(key)];

    printf("\nDecrypted Text: %s\n", text);

    return 0;
}

