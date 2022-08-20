#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
int i=1;
int times=0;
int a=0, b=0, c=0;
//            2         a        b        c
void tower(int n, char from, char to, char aux, int m)
{//           1          a        c
    if(n==1){
        //printf("%c => %c    ", from, to);
        times++;
        //printf("times: %d\n", times);

        if(from=='A'&&to=='B'){
            a--;    b++;
            if(m==times)
            printf("A: %d, B: %d, C: %d\n",a,b,c);
        }
        if(from=='A'&&to=='C'){
            a--;    c++;
            if(m==times)
            printf("A: %d, B: %d, C: %d\n",a,b,c);
        }
        if(from=='B'&&to=='A'){
            b--;    a++;
            if(m==times)
            printf("A: %d, B: %d, C: %d\n",a,b,c);
        }
        if(from=='B'&&to=='C'){
            b--;    c++;
            if(m==times)
            printf("A: %d, B: %d, C: %d\n",a,b,c);
        }
        if(from=='C'&&to=='A'){
            c--;    a++;
            if(m==times)
            printf("A: %d, B: %d, C: %d\n",a,b,c);
        }
        if(from=='C'&&to=='B'){
            c--;    b++;
            if(m==times)
            printf("A: %d, B: %d, C: %d\n",a,b,c);
        }


        return;
    }
//          1   a      c   b
    tower(n-1, from, aux, to, m);//將n底上 n-1個discs移至 aux
//             a    b
    tower(1, from, to, aux, m);//將你要移動n底從a移到to
//         1    c   b
    tower(n-1, aux, to, from, m);//將移動至aux的discs移回to

}
int main()
{
    int n;
    int m;
    char A, B, C;

    printf("請輸入河內塔層數: ");
    scanf("%d", &n);

    printf("請輸入第幾步驟的狀況: ");
    scanf("%d", &m);

    a=n;
    tower(n, 'A', 'B', 'C', m);


    return 0;
}
