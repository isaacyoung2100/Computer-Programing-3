#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20
#define ALL 1140

int main()
{
    int i, j, k, n=0;
    int a[SIZE], s[ALL]={0};
    int co[ALL][3];
    int sum, cloest, flag;
    int *p;


    srand( time(NULL));
    for(p=a ; p<a+SIZE ; p++)
    {
        *p=rand()%50;//�j�p���G�Q���}�C �ζüƨ���
        printf("%d  ", *p);
    }printf("\n");

    printf("��J�T���`�X: ");
    scanf("%d", &sum);

    for(i=0 ; i<SIZE ; i++)//�p��Ҧ��զX�A���Ҩ������ؤ��୫��
        for(j=i+1 ; j<SIZE ; j++)
            for(k=j+1 ; k<SIZE ; k++){
                *(s+n)=*(a+i)+*(a+j)+*(a+k);
                *(*(co+n)+0)=*(a+i);
                *(*(co+n)+1)=*(a+j);
                *(*(co+n)+2)=*(a+k);
                n++;
            }


    for(i=0 ; i<ALL ; i++){
        printf("%d: coumbine= ", i);
        for(j=0 ; j<3 ; j++)
        {
            printf("%3d", co[i][j]);
        }
        printf(",sum= %d\n", s[i]);
        i++;
    }


    for(i=0 ; i<ALL ; i++)
        //�p��Ҧ��զX�Msum���Z��
    {
        *(s+i)-=sum;
        if(*(s+i)<0)
            *(s+i)=-*(s+i);

        if(i==0)
            cloest=*s;

        if(*(s+i)<cloest)
        {
            cloest=*(s+i);
            flag=i;
        }

    }

    for(i=0 ; i<3 ; i++)
    {
        printf("%d ", *(*(co+flag)+i));
    }
    return 0;

}
