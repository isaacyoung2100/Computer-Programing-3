#include <stdio.h>
#include <stdlib.h>
#define SIZE 5002//���{���ڭ̤��ϥβĹs��,�Ĥ@������l��=�Ӧ��
int findmin(int l[], int r[], int m[], int tot)//mid�|�񥪥k�h�@��
{
    int i, k;
    for(i=1 ; i<=tot ; i++){//���[�`
        m[i]=l[i]+r[i];//���ӳ��[��mid���Y
        if(m[i]>=10){
            m[i-1]+=(m[i]/10);
            m[i]%=10;
        }
    }

    /*//�L�X�[�`�᪺mid
    printf("�[�`��m: \n");
    for(k=1 ; k<=tot+1 ; k++){
        printf("%d ", m[k]);
    }printf("\n");*/

    //��2
    for(i=1 ; i<=tot+1 ; i++){
        if(m[i]%2!=0){
            m[i+1]=m[i+1]+(m[i]%2)*10;
        }
        m[i]/=2;
    }

    //�L�X�̲�mid
    /*printf("��2:\n");
    for(k=1 ; k<=tot+1 ; k++){
            printf("%d %d %d\n", l[k], r[k], m[k]);
        }
    printf("find mid end -----------------\n");*/
}
int LorR(int m[], int tot)//�@�X��
{
    //1+1+(tot-1)*2: ����Ȧ@�h�ּ�, �Ĺs�����ϥ��ٻݥ[�@
    int i, j, k, flag=1;
    int fin=1+1+(tot-1)*2;
        //printf("fin(sum�}�C�j�p): %d\n", fin);
    int sum[fin];//�Ψ��x�s�����
    for(i=1 ; i<=fin ; i++)
        sum[i]=0;
    //printf("tot: %d\n", tot);
    //printf("m: \n");
    /*for(k=1 ; k<=tot ; k++){
        printf("%d ", m[k]);
    }printf("\n");*/

    for(i=1 ; i<=tot; i++){//step1
        for(j=1, k=flag ; j<=tot ; j++, k++){
            sum[k]=sum[k]+m[i]*m[j];
            //printf("%d: %d%d--%d=%d*%d\n",k,i,j,sum[k],m[i],m[j]);
        }
        flag++;
    }

    /*printf("sum:\n");
    for(k=1 ; k<=tot+1 ; k++){
        printf("%d ", sum[k]);
    }printf("\n");*/

    for(i=fin-1 ; i>0 ; i--){
        if(sum[i]>=10){
            sum[i-1]+=sum[i]/10;
            sum[i]=sum[i]-(sum[i]/10)*10;
        }
    }

    /*printf("�ӼƦ���j�p��:\n");
    for(k=1 ; k<=fin-1 ; k++){
        printf("%d  ", sum[k]);
    }printf("\n");*/

    if(sum[1]==1)//�N������ƬO�@�I�h
        return  1;
    else
        return  0;//�N������ƬO�G�}�Y

}
int main()
{
    int i, j, k, d;
    int L[SIZE]={0}, R[SIZE]={0}, M[SIZE]={0};//L[101],R[101],M[101]
    L[1]=1, R[1]=2;//�]�m��l��=�Ӧ�Ʀr
//             i<102
    /*printf("first\n");
    for(k=1 ; k<SIZE ; k++){
            printf("%d %d %d\n", L[k], R[k], M[k]);
        }printf("\n");*/
    for(i=1 ; i<SIZE ; i++)//�`�@���h�ּ�
    {//                  1
        findmin(L, R, M, i);//��mid,i���`���X�Ӽ�
        //���ɦ^�Ǫ�M�|�h�@��

        /*for(k=1 ; k<SIZE ; k++){
            printf("%d %d %d\n", L[k], R[k], M[k]);
        }printf("\n");*/

        if(LorR(M, i+1)){//M������Ƭ��@�}�Y
            for(j=1 ; j<SIZE ; j++)
                L[j]=M[j];
        }
        else{
            for(j=1 ; j<SIZE ; j++)
                R[j]=M[j];
        }

        /*printf("�ק��\n");
        for(k=1 ; k<SIZE ; k++){
            printf("%d %d %d\n", L[k], R[k], M[k]);
        }printf("\n");*/
    }

    for(i=1 ; i<SIZE ; i++){
        printf("%d", M[i]);

    }


    return 0;
}
