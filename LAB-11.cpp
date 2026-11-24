
#include <stdio.h>
#include <math.h>

int main() {
    double keys = 1;
    int i;

    for (i = 1; i <= 25; i++)
        keys *= i;

    printf("Total possible keys = 25! = %.0f\n", keys);
    printf("Approximate power of 2 = 2^%.2f\n", log2(keys));

    printf("Effectively unique keys = 25! / (24! * 2^24)\n");
    printf("Approximate power of 2 = 2^%.2f\n",
           log2(keys) - log2(24) - 24);

    return 0;
}

