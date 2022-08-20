#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 101
int oddkind(char arr[], int i)//i��1��100��
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
        //k�q0,j�q1
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

    for(i=1 ; i<MAX ; i++)//�Q�ζüưt�m�^��r����}�C��
    {
        arr[i]=rand()%26+65;
    }

    printf("�j��: \n");
    for(i=1 ; i<MAX ; i++)//�N�Ҧ��ü���ܦb�ù��W
    {
        printf("%c\t", arr[i]);
        if(i%10==0)     printf("\n");
    }


    for(i=1 ; i<MAX ; i++)//�N�Ҧ����r��������,�p��: 1.�_�ưj�� 2.���ưj��,�ñN��g�Jans�}�C��
    {
        printf("%c\n", arr[i]);
        sum+=(oddkind(arr, i)+unoddkind(arr, i)+1);
    }


    printf("�j�j�p�p���j���`�@��: %d\n", sum);

    return 0;
}
