#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int Lstart, int Lend, int Rstart, int Rend)//皆為其位置
{
    int size=Rend-Lstart+1, i=Lstart, j=Rstart;//左右兩大分部一定是連續的
    printf("Lend= %d, Rstart= %d\n", Lend, Rstart);
    int buffer[size], k=0;

    while(i<=Lend && j<=Rend)//左右邊互比，比較小的丟近暫存器
        if(a[i] <= a[j])
            buffer[k++] = a[i++];
        else
            buffer[k++] = a[j++];


    while(i<=Lend)  buffer[k++] = a[i++];
    while(j<=Rend)  buffer[k++] = a[j++];

    for (i=Lstart, j=0; i<=Rend; i++)
        a[i] = buffer[j++];

    return;
}

void mergesort(int a[], int left, int right)
{
    if(left==right)   return;

    int mid = (left+right)/2;//用(left+right)/2來切分

    //左右邊會分到底 分到一個項目一格
    mergesort(a, left, mid);
    mergesort(a, mid+1, right);
    merge(a, left, mid, mid+1, right);

    return;
}


int main(void)
{
    int list[20] = {88, 34, 26, 95, 98, 12, 85, 45, 66, 29, 44, 41, 78, 30, 21, 66, 1, 8, 0, 20};

    mergesort(list, 0, 19);//left = 0, right = size - 1;

    for(int i=0; i<20; i++)
        printf("%d ", list[i]);
    printf("\n");

    return 0;
}
