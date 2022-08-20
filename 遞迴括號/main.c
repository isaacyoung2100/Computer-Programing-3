#include <stdio.h>
#include <stdlib.h>
int determine(char a[], int last)
{
    if(a[last]=='(')    return 0;
    int i, right=0, pause, check;

    for(i=last ; i>=0 ; i--){//n=7;n=1
        if(a[i]==')')
            right++;//right=3;right=1
        else{
            pause=i;//i走到4,pause=4;i走至0,pause=0
            break;
        }
    }
    check=pause-right+1;//check=
    if(check<0)
        return 0;
//         7           5
//         0           0
   for(i=pause ; i>=check ; i--){
        if(a[i]==')')
            return 0;
        if(i==0)     return 1;
   }

   determine(a,--check);
}
int main()
{
    int i=0,j,last;
    char arr[100];

    printf("請輸入一串括號(按0結束):\n");

    /*for(;; i++){
        scanf("%c", arr+i);
        if(arr[i]=='\n')    break;
    }*/
    do{
        scanf("%c", arr+i);
    }while(arr[i++]!='\n');
    printf("%d\n",i-2);

    for(j=0 ; j<i ; j++)
    {
        printf("%c", arr[j]);
    }
    printf("\n");

    if(determine(arr,i-2))
        printf("right.");
    else
        printf("false.");
    return 0;
}
