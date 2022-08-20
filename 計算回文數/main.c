#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 101
int oddkind(char arr[], int i)//i為1至100項
{
    int j, counter=0;
    int k;

    for(j=1 ; j<MAX ; j++){
        if(i-j<=0||i+j>MAX)   break;

        if(arr[i+j]==arr[i-j]){
            counter++;
            for(k=i-j ; k<=i+j ; k++)
                printf("%c", arr[k]);
            printf("\n");
        }
        else    break;
    }

    return counter;
}
int unoddkind(char arr[], int i)
{
    int j, counter=0;
    int k=0;

    for(j=1 ; j<MAX ; j++)
    {
        //k從0,j從1
        if(i-k<=0||i+j>MAX)   break;
        if(arr[i-(j-1)]==arr[i+j]){
            //printf("%c%c ",arr[i-k],arr[i+j]);
            counter++;
            for(k=i-(j-1) ; k<=i+j ; k++)
                printf("%c", arr[k]);
            printf("\n");
        }
        else    break;
    }
    return counter;
}
int main()
{
    char arr[MAX];
    int i, j=1;
    int sum=0;


    srand( time(NULL));

    for(i=1 ; i<MAX ; i++)//利用亂數配置英文字母到陣列中
    {
        arr[i]=rand()%26+65;
    }

    printf("迴文: \n");
    for(i=1 ; i<MAX ; i++)//將所有亂數顯示在螢幕上
    {
        printf("%c\t", arr[i]);
        if(i%10==0)     printf("\n");
    }


    for(i=1 ; i<MAX ; i++)//將所有的字母為中心,計算: 1.奇數迴文 2.偶數迴文,並將其寫入ans陣列當中
    {
        printf("%c\n", arr[i]);
        sum+=(oddkind(arr, i)+unoddkind(arr, i)+1);
    }


    printf("大大小小的迴文總共有: %d\n", sum);

    return 0;
}
