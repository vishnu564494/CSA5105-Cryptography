#include <stdio.h>
#include <ctype.h>

char a[5][5];

void makeMatrix(char key[])
{
    int used[26]={0}, i,j,k=0;
    char c;

    used['J'-'A']=1;

    for(i=0; key[i]; i++) {
        c=toupper(key[i]);
        if(c=='J') c='I';
        if(c>='A' && c<='Z' && !used[c-'A']) {
            a[k/5][k%5]=c;
            used[c-'A']=1;
            k++;
        }
    }

    for(c='A'; c<='Z'; c++)
        if(!used[c-'A']) {
            a[k/5][k%5]=c;
            used[c-'A']=1;
            k++;
        }
}

void pos(char c,int *r,int *col)
{
    int i,j;
    if(c=='J') c='I';

    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            if(a[i][j]==c) {
                *r=i; *col=j;
            }
}

int main()
{
    char key[30],s[100],out[100];
    int i,n=0,r1,c1,r2,c2;

    printf("Enter keyword: ");
    scanf("%s",key);

    printf("Enter plaintext: ");
    scanf("%s",s);

    makeMatrix(key);

    printf("\nMatrix:\n");
    for(i=0;i<5;i++)
        printf("%c %c %c %c %c\n",
        a[i][0],a[i][1],a[i][2],a[i][3],a[i][4]);

    for(i=0;s[i];i+=2) {
        char x=toupper(s[i]);
        char y=s[i+1]?toupper(s[i+1]):'X';

        pos(x,&r1,&c1);
        pos(y,&r2,&c2);

        if(r1==r2) {
            out[n++]=a[r1][(c1+1)%5];
            out[n++]=a[r2][(c2+1)%5];
        }
        else if(c1==c2) {
            out[n++]=a[(r1+1)%5][c1];
            out[n++]=a[(r2+1)%5][c2];
        }
        else {
            out[n++]=a[r1][c2];
            out[n++]=a[r2][c1];
        }
    }

    out[n]='\0';
    printf("Ciphertext: %s",out);

    return 0;
}
