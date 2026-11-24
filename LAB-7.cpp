
#include <stdio.h>
#include <string.h>

int main()
{
    char cipher[] =
    "53DDX305))6*;4826)4D.)4D);806*;48X8V60))85;;"
    "]8*;:D*8X83"
    "(88)5*X;46(;88*96*?;8)*D(;485);5*X2:*D(;4956*"
    "2(5*C4)8V8*;4069285);)6X8)4DD;1(D9;48081;"
    "8:8D1;48X85;4)485X528806*81"
    "(D9;48;(88;4(D?34;48)4D;161;:188;D?;";

    char *p;

    printf("Decrypted Message:\n\n");

    for(p = cipher; *p != '\0'; p++)
    {
        switch(*p)
        {
            case '5': printf("a"); break;
            case '3': printf("g"); break;
            case 'D': printf("o"); break;
            case 'X': printf("d"); break;
            case '0': printf("l"); break;
            case ')': printf("s"); break;
            case '6': printf("i"); break;
            case '*': printf("n"); break;
            case ';': printf("t"); break;
            case '4': printf("h"); break;
            case '8': printf("e"); break;
            case '2': printf("b"); break;
            case '.': printf("p"); break;
            case 'V': printf("v"); break;
            case ']': printf("w"); break;
            case ':': printf("y"); break;
            case '(': printf("r"); break;
            case '9': printf("m"); break;
            case '?': printf("u"); break;
            case 'C': printf("c"); break;
            case '1': printf("f"); break;
            default: printf("%c", *p);
        }
    }

    printf("\n");

    return 0;
}

