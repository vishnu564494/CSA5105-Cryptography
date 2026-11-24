
#include <stdio.h>

int main()
{
    int e = 7, n = 187;
    int i, j, m, c, result;
    char text[100];

    printf("Enter plaintext: ");
    scanf("%s", text);

    printf("\nRSA ENCRYPTION\n");

    for(i = 0; text[i] != '\0'; i++)
    {
        m = text[i] - 'A';

        result = 1;

        for(j = 0; j < e; j++)
            result = (result * m) % n;

        c = result;

        printf("%d ", c);
    }

    printf("\n\nRSA SECURITY ANALYSIS\n");
    printf("Individual character encryption is NOT secure.\n");
    printf("Only 26 possible plaintext values exist.\n");
    printf("An attacker can try all 26 values.\n");
    printf("This is called a brute-force attack.\n");

    return 0;
}

