
#include <stdio.h>

int main()
{
    int C[28], D[28], K[48];
    int i, j, round, temp;
    
    int shift[16] = {
        1,1,2,2,2,2,2,2,
        1,2,2,2,2,2,2,1
    };

    printf("Enter first 28 bits:\n");
    for(i=0;i<28;i++)
        scanf("%1d",&C[i]);

    printf("Enter second 28 bits:\n");
    for(i=0;i<28;i++)
        scanf("%1d",&D[i]);

    for(round=0;round<16;round++)
    {
        for(j=0;j<shift[round];j++)
        {
            temp=C[0];
            for(i=0;i<27;i++)
                C[i]=C[i+1];
            C[27]=temp;

            temp=D[0];
            for(i=0;i<27;i++)
                D[i]=D[i+1];
            D[27]=temp;
        }

        printf("\nSubkey K%d: ",round+1);

        for(i=0;i<24;i++)
            printf("%d",C[i]);

        for(i=0;i<24;i++)
            printf("%d",D[i]);
    }

    return 0;
}

