#include <stdio.h>
#include <stdlib.h>
int a=0, b=0, c=0;
int c1, c2, c3;
//   0   2   2
int k;
int cc, ccc, cccc;

void tower(int n, char from, char to, char aux, char ar[], char br[], char cr[])
{
    char temp;
    //printf("%d,", n);
    int i;
    static int times=0;
    if(n==1)
    {
        printf("n=1: %c => %c\n", from, to);
        //printf("c1= %d, c2= %d, c3= %d\n", c1,c2,c3);
        times++;
        printf("¹Ï§Î: \n");
        if(from=='A'&&to=='B')
        {
            a--;
            b++;
            //for(i=2 ; i>0 ; i++)
              //  if(ar[c]!=' '&&br[cc]!=' '){
                temp=ar[c1];
                ar[c1]=br[c2];
                br[c2]=temp;
                c1++;//1
                c2--;//1
                //}

            for(i=0 ; i<k ; i++)
            {
                printf("%4c%4c%4c\n", ar[i], br[i], cr[i]);
            }
            printf("A: %d, B: %d, C: %d\n\n",a,b,c);
        }
        if(from=='A'&&to=='C')
        {
            a--;
            c++;
            temp=ar[c1];
            ar[c1]=cr[c3];
            cr[c3]=temp;
            c1++;//2
            c3--;//1

            for(i=0 ; i<k ; i++)
            {
                printf("%4c%4c%4c\n", ar[i], br[i], cr[i]);
            }
            printf("A: %d, B: %d, C: %d\n\n",a,b,c);
        }
        if(from=='B'&&to=='A')
        {
            b--;
            a++;
            temp=br[c2];
            br[c2]=ar[c1];
            ar[c1]=temp;
            c2++;
            c1--;

            for(i=0 ; i<k ; i++)
            {
                printf("%4c%4c%4c\n", ar[i], br[i], cr[i]);
            }
            printf("A: %d, B: %d, C: %d\n\n",a,b,c);
        }
        if(from=='B'&&to=='C')
        {
            b--;
            c++;
            temp=br[c2];
            br[c2]=cr[c3];
            cr[c3]=temp;
            c2++;
            c3--;
            for(i=0 ; i<k ; i++)
            {
                printf("%4c%4c%4c\n", ar[i], br[i], cr[i]);
            }
            printf("A: %d, B: %d, C: %d\n\n",a,b,c);
        }
        if(from=='C'&&to=='A')
        {
            c--;
            a++;
            temp=ar[c1];
            ar[c1]=cr[c3];
            cr[c3]=temp;
            c3++;
            c1--;
            for(i=0 ; i<k ; i++)
            {
                printf("%4c%4c%4c\n", ar[i], br[i], cr[i]);
            }
            printf("A: %d, B: %d, C: %d\n\n",a,b,c);
        }
        if(from=='C'&&to=='B')
        {
            c++;
            b--;
            temp=cr[c3];
            cr[c3]=br[c2];
            br[c2]=temp;
            c3--;
            c2++;
            for(i=0 ; i<k ; i++)
            {
                printf("%4c%4c%4c\n", ar[i], br[i], cr[i]);
            }
            printf("A: %d, B: %d, C: %d\n\n",a,b,c);
        }

        return;
    }

    tower(n-1, from, aux, to, ar, br, cr);
    tower(1, from, to, aux, ar, br, cr);
    tower(n-1, aux, to, from, ar, br, cr);
    // printf("n= %d,times= %d\n", n, times);
}
int main()
{

    int n, i;
    char A, B, C;
    scanf("%d", &n);
    char ar[n], br[n], cr[n];

    a=n, k=n;
    for(i=0 ; i<n ; i++)
    {
        br[i]=' ';
        cr[i]=' ';
        if(i%2==1)
            ar[i]='g';
        else
            ar[i]='b';
    }
    for(i=0 ; i<n ; i++)
    {
        printf("%4c%4c%4c\n", ar[i], br[i], cr[i]);
    }
    printf("   A   B   C\n");
    c1=0, c2=c3=n-1;

    tower(n, 'A', 'B', 'C', ar, br, cr);
    return 0;
}

