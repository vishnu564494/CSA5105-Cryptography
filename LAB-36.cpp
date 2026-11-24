
#include <stdio.h>
#include <string.h>

int main()
{
    char text[100];
    int a, b, i, p, c;

    printf("Enter plaintext: ");
    scanf("%s", text);

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of b: ");
    scanf("%d", &b);

    // Check whether a is valid
    if (a % 2 == 0 || a % 13 == 0)
    {
        printf("Invalid value of a");
        return 0;
    }

    printf("Encrypted text: ");

    for (i = 0; text[i] != '\0'; i++)
    {
        p = text[i] - 'A';
        c = (a * p + b) % 26;
        printf("%c", c + 'A');
    }

    return 0;
}

