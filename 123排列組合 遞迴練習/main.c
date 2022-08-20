#include <stdio.h>
#include <stdlib.h>
//                     0          3
void pie(int a[], int pass, int size){
    int i, hold;

    if(pass==size){
        for(i=0 ; i<size ; i++)
            printf("%d ", a[i]);
        printf("\n");
        return;
    }

    else{//    2        3
        for(i=pass ; i<size ; i++){
            //printf("pass = %d: \n", pass);
            //printf("i=%d\n", i);
            hold=a[i];
            a[i]=a[pass];//4 5
            a[pass]=hold;

            pie(a, pass+1, size );//a 1 3/a 2 3/a 3 3

            hold=a[i];
            a[i]=a[pass];
            a[pass]=hold;
            //printf("i=%d,k\n", i);
        }

    }


}

int main()
{
    int a[5000]={0};
    int size, i;

    printf("輸入 1~10 ");
    scanf("%d", &size);//3

    printf("輸入整數 ");
    for(i=0 ; i<size ; i++)
        scanf("%d", &a[i]);//1 2 3

    pie(a,0,size);


    return 0;
}
