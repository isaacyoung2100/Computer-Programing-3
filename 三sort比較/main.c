#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 8000
void quicksort(int a[], int left, int right)
{
    int pivot, i, j;

    if(left >= right)
      return;

    i = left;    j = right+1;   pivot = a[left];

    do
    {
        do i++; while(a[i] < pivot && i<right);
        do j--; while(a[j] > pivot && left<j);
        if(i < j)
        {
            int temp;
            temp = a[i];  a[i] = a[j];  a[j] = temp;
        }
    } while(i < j);

    int temp;
    temp = a[left];  a[left] = a[j];  a[j] = temp;

    quicksort(a, left, j-1);
    quicksort(a, j+1, right);
    return;

}
void merge(int a[], int Lstart, int Lend, int Rstart, int Rend)
{
    int size=Rend-Lstart+1, i=Lstart, j=Rstart;
    int buffer[size], k=0;

    while(i<=Lend && j<=Rend)
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

    int mid = (left+right)/2;

    mergesort(a, left, mid);
    mergesort(a, mid+1, right);
    merge(a, left, mid, mid+1, right);

    return;
}
void bubblesort(int a[])
{
    int pass,i,hold;
    for(pass=1;pass<SIZE;pass++){
        for(i=0;i<SIZE-1;i++){
            if(a[i]>a[i+1]){
                hold=a[i];
                a[i]=a[i+1];
                a[i+1]=hold;
        }
        }
    }
}

int main()
{
    clock_t t1, t2, k1, k2, u1, u2;
    double sumt=0, sumk=0, sumu=0;
    int i,j,t=0, co=0;
    int a[SIZE],b[SIZE],c[SIZE];

    srand( time(NULL));

    while(1){
        co++;
        for(i=0 ; i<SIZE ; i++)
            a[i]=b[i]=c[i]=rand()%10000;

        t1=clock();
        quicksort(a,0,SIZE-1);
        t2=clock();
        sumt+=(t2-t1);

        k1=clock();
        mergesort(b,0,SIZE-1);
        k2=clock();
        sumk+=(k2-k1);

        u1=clock();
        bubblesort(c);
        u2=clock();
        sumu+=(u2-u1);

        if(co==10)
            break;
    }
    printf("quickdiffference= %f\n", sumt/CLOCKS_PER_SEC);
    printf("mergediffference= %f\n", sumk/CLOCKS_PER_SEC);
    printf("bubblediffference= %f\n", sumu/CLOCKS_PER_SEC);
    return 0;
}
