#include <stdio.h>
#include <ctype.h>

int main() {
    char p[100];
    int a, b, i;

    printf("Enter plaintext: ");
    scanf("%99s", p);

    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);

    for (i = 0; p[i]; i++) {
        p[i] = (a * (toupper(p[i]) - 'A') + b) % 26 + 'A';
    }

    printf("Ciphertext: %s\n", p);
    return 0;
}
