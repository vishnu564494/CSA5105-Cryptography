
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char key[100], text[200];
    char a[5][5];
    int i, j, k, r1, c1, r2, c2;
    char used[26] = {0};

    printf("Enter key: ");
    scanf("%s", key);

    k = 0;
    for (i = 0; key[i]; i++) {
        char ch = toupper(key[i]);
        if (ch == 'J') ch = 'I';
        if (ch >= 'A' && ch <= 'Z' && !used[ch-'A']) {
            a[k/5][k%5] = ch;
            used[ch-'A'] = 1;
            k++;
        }
    }

    for (i = 0; i < 26; i++) {
        if (i == 9) continue;
        if (!used[i]) {
            a[k/5][k%5] = 'A' + i;
            k++;
        }
    }

    printf("Enter ciphertext: ");
    scanf(" %[^\n]", text);

    for (i = 0; text[i]; i++)
        if (isalpha(text[i]))
            text[i] = toupper(text[i]);

    for (i = 0; text[i] && text[i+1]; i += 2) {
        if (!isalpha(text[i]) || !isalpha(text[i+1])) {
            i--;
            continue;
        }

        char x = text[i], y = text[i+1];
        if (x == 'J') x = 'I';
        if (y == 'J') y = 'I';

        for (r1=0; r1<5; r1++)
            for (c1=0; c1<5; c1++) {
                if (a[r1][c1] == x) goto found1;
            }
        found1:

        for (r2=0; r2<5; r2++)
            for (c2=0; c2<5; c2++) {
                if (a[r2][c2] == y) goto found2;
            }
        found2:

        if (r1 == r2) {
            text[i] = a[r1][(c1+4)%5];
            text[i+1] = a[r2][(c2+4)%5];
        } else if (c1 == c2) {
            text[i] = a[(r1+4)%5][c1];
            text[i+1] = a[(r2+4)%5][c2];
        } else {
            text[i] = a[r1][c2];
            text[i+1] = a[r2][c1];
        }
    }

    printf("Decrypted message: %s\n", text);
    return 0;
}

