#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char p[100], key[100];
    int i, j = 0;

    printf("Enter plaintext: ");
    scanf("%99s", p);

    printf("Enter key: ");
    scanf("%99s", key);

    for (i = 0; p[i]; i++) {
        p[i] = (toupper(p[i]) - 'A' +
                toupper(key[j % strlen(key)]) - 'A') % 26 + 'A';
        j++;
    }

    printf("Ciphertext: %s\n", p);
    return 0;
}
