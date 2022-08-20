#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int Lstart, int Lend, int Rstart, int Rend)//�Ҭ����m
{
    int size=Rend-Lstart+1, i=Lstart, j=Rstart;//���k��j�����@�w�O�s��
    printf("Lend= %d, Rstart= %d\n", Lend, Rstart);
    int buffer[size], k=0;

    while(i<=Lend && j<=Rend)//���k�䤬��A����p�����Ȧs��
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

    int mid = (left+right)/2;//��(left+right)/2�Ӥ���

    //���k��|���쩳 ����@�Ӷ��ؤ@��
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
