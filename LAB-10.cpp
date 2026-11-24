
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char a[5][5] = {
        {'M','F','H','I','K'},
        {'U','N','O','P','Q'},
        {'Z','V','W','X','Y'},
        {'E','L','A','R','G'},
        {'D','S','T','B','C'}
    };

    char text[200], out[300];
    int i, j, r1, c1, r2, c2, k = 0;

    printf("Enter message: ");
    fgets(text, sizeof(text), stdin);

    char msg[200];
    j = 0;

    for (i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            char ch = toupper(text[i]);
            if (ch == 'J') ch = 'I';
            msg[j++] = ch;
        }
    }
    msg[j] = '\0';

    for (i = 0; i < j; i += 2) {
        char x = msg[i];
        char y;

        if (i + 1 >= j) y = 'X';
        else if (x == msg[i + 1]) y = 'X';
        else y = msg[i + 1];

        for (r1 = 0; r1 < 5; r1++)
            for (c1 = 0; c1 < 5; c1++)
                if (a[r1][c1] == x) goto found1;
        found1:

        for (r2 = 0; r2 < 5; r2++)
            for (c2 = 0; c2 < 5; c2++)
                if (a[r2][c2] == y) goto found2;
        found2:

        if (r1 == r2) {
            out[k++] = a[r1][(c1 + 1) % 5];
            out[k++] = a[r2][(c2 + 1) % 5];
        } else if (c1 == c2) {
            out[k++] = a[(r1 + 1) % 5][c1];
            out[k++] = a[(r2 + 1) % 5][c2];
        } else {
            out[k++] = a[r1][c2];
            out[k++] = a[r2][c1];
        }
    }

    out[k] = '\0';
    printf("Encrypted message: %s\n", out);

    return 0;
}
