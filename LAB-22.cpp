
#include <stdio.h>
#include <string.h>

int P10[]={3,5,2,7,4,10,1,9,8,6};
int P8[]={6,3,7,4,8,5,10,9};
int IP[]={2,6,3,1,4,8,5,7};
int IP1[]={4,1,3,5,7,2,8,6};
int EP[]={4,1,2,3,2,3,4,1};
int P4[]={2,4,3,1};

int S0[4][4]={
 {1,0,3,2},
 {3,2,1,0},
 {0,2,1,3},
 {3,1,3,2}
};

int S1[4][4]={
 {0,1,2,3},
 {2,0,1,3},
 {3,0,1,0},
 {2,1,0,3}
};

int permute(int x,int t[],int n,int bits)
{
    int result=0,i;

    for(i=0;i<n;i++)
    {
        result=(result<<1) |
        ((x>>(bits-t[i]))&1);
    }

    return result;
}

void generateKeys(int key,int *k1,int *k2)
{
    int p=permute(key,P10,10,10);
    int l=(p>>5)&31;
    int r=p&31;

    l=((l<<1)&31)|(l>>4);
    r=((r<<1)&31)|(r>>4);

    *k1=permute((l<<5)|r,P8,8,10);

    l=((l<<2)&31)|(l>>3);
    r=((r<<2)&31)|(r>>3);

    *k2=permute((l<<5)|r,P8,8,10);
}

int F(int r,int key)
{
    int x=permute(r,EP,8,4)^key;

    int a=(x>>4)&63;
    int b=x&63;

    int row=((a>>5)&1)*2+(a&1);
    int col=(a>>1)&3;

    int s0=S0[row][col];

    row=((b>>5)&1)*2+(b&1);
    col=(b>>1)&3;

    int s1=S1[row][col];

    return permute((s0<<2)|s1,P4,4,4);
}

int encrypt(int x,int k1,int k2)
{
    int p=permute(x,IP,8,8);

    int l=p>>4;
    int r=p&15;
    int temp;

    l=l^F(r,k1);

    temp=l;
    l=r;
    r=temp;

    l=l^F(r,k2);

    return permute((l<<4)|r,IP1,8,8);
}

int decrypt(int x,int k1,int k2)
{
    int p=permute(x,IP,8,8);

    int l=p>>4;
    int r=p&15;
    int temp;

    l=l^F(r,k2);

    temp=l;
    l=r;
    r=temp;

    l=l^F(r,k1);

    return permute((l<<4)|r,IP1,8,8);
}

void display(int a[],int n)
{
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=7;j>=0;j--)
            printf("%d",(a[i]>>j)&1);

        printf(" ");
    }
    printf("\n");
}

int main()
{
    int key=0b0111111101;
    int iv=0b10101010;

    int plain[]={0b00000001,0b00100011};
    int cipher[2],recovered[2];

    int k1,k2,i,previous;

    generateKeys(key,&k1,&k2);

    // CBC ENCRYPTION
    previous=iv;

    for(i=0;i<2;i++)
    {
        cipher[i]=encrypt(plain[i]^previous,k1,k2);
        previous=cipher[i];
    }

    printf("CBC ENCRYPTION\n");
    printf("Plaintext : ");
    display(plain,2);

    printf("Ciphertext: ");
    display(cipher,2);

    // CBC DECRYPTION
    previous=iv;

    for(i=0;i<2;i++)
    {
        recovered[i]=decrypt(cipher[i],k1,k2)^previous;
        previous=cipher[i];
    }

    printf("\nCBC DECRYPTION\n");
    printf("Ciphertext: ");
    display(cipher,2);

    printf("Plaintext : ");
    display(recovered,2);

    return 0;
}

