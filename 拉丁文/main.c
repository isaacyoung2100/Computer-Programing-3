#include <stdio.h>
#include <stdlib.h>

int readline(char *p, int n)
{
    int i=0;

    for(; i<n && (*(p+i) = getchar()) != '\n'; i++)
        ;
    *(p+i) = '\0';
    return i;//共存了多少字串但不包括斜線零
}
int  transform(char *ou, int temp, int flag, const char *in, int tend)
{
    int i=temp+1;
    int j=tend;
    for( ; i<flag ; i++, j++)
        *(ou + j) = *(in + i);
    //    新字串        舊字串
    *( ou+j ) = *( in+temp );
    *( ou+j+1 ) = 'a';
    *( ou+j+2 ) = 'y';
    *( ou+j+3 ) = ' ';
    *( ou+j+4 ) = '\0';

    return j+4;//7
}
int main()
{
    char inputwords[200+1];
    int i, n, j, k;
    char outputwords[200+1];
    char answer[5][80+1];
    n = readline(inputwords, 100);

    int temp=0, flag=0, tend=0;
    for( i = 0; i <= n; i ++ )
    {
        if(inputwords[i] == ' ' || i==n){
            flag = i;
            tend = transform(outputwords, temp, flag, inputwords, tend);
            temp = flag + 1;
        }
    }
    int rows=tend/80;i=tend;
    do{
        outputwords[i++]='a';
    }while(i%80!=0);

    printf("%s", outputwords);
    printf("%d%d", tend, i);
    return 0;
}
//qwer asdf zxcv
