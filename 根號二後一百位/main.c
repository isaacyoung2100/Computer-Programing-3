#include <stdio.h>
#include <stdlib.h>
#define SIZE 5002//此程式我們不使用第零項,第一項為初始值=個位數
int findmin(int l[], int r[], int m[], int tot)//mid會比左右多一位
{
    int i, k;
    for(i=1 ; i<=tot ; i++){//先加總
        m[i]=l[i]+r[i];//給個都加到mid裏頭
        if(m[i]>=10){
            m[i-1]+=(m[i]/10);
            m[i]%=10;
        }
    }

    /*//印出加總後的mid
    printf("加總後m: \n");
    for(k=1 ; k<=tot+1 ; k++){
        printf("%d ", m[k]);
    }printf("\n");*/

    //除2
    for(i=1 ; i<=tot+1 ; i++){
        if(m[i]%2!=0){
            m[i+1]=m[i+1]+(m[i]%2)*10;
        }
        m[i]/=2;
    }

    //印出最終mid
    /*printf("除2:\n");
    for(k=1 ; k<=tot+1 ; k++){
            printf("%d %d %d\n", l[k], r[k], m[k]);
        }
    printf("find mid end -----------------\n");*/
}
int LorR(int m[], int tot)//共幾位
{
    //1+1+(tot-1)*2: 平方值共多少數, 第零項不使用還需加一
    int i, j, k, flag=1;
    int fin=1+1+(tot-1)*2;
        //printf("fin(sum陣列大小): %d\n", fin);
    int sum[fin];//用來儲存平方值
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

    /*printf("該數次方大小為:\n");
    for(k=1 ; k<=fin-1 ; k++){
        printf("%d  ", sum[k]);
    }printf("\n");*/

    if(sum[1]==1)//代表此平方數是一點多
        return  1;
    else
        return  0;//代表此平方數是二開頭

}
int main()
{
    int i, j, k, d;
    int L[SIZE]={0}, R[SIZE]={0}, M[SIZE]={0};//L[101],R[101],M[101]
    L[1]=1, R[1]=2;//設置初始值=個位數字
//             i<102
    /*printf("first\n");
    for(k=1 ; k<SIZE ; k++){
            printf("%d %d %d\n", L[k], R[k], M[k]);
        }printf("\n");*/
    for(i=1 ; i<SIZE ; i++)//總共有多少數
    {//                  1
        findmin(L, R, M, i);//找mid,i為總有幾個數
        //此時回傳的M會多一位

        /*for(k=1 ; k<SIZE ; k++){
            printf("%d %d %d\n", L[k], R[k], M[k]);
        }printf("\n");*/

        if(LorR(M, i+1)){//M的平方數為一開頭
            for(j=1 ; j<SIZE ; j++)
                L[j]=M[j];
        }
        else{
            for(j=1 ; j<SIZE ; j++)
                R[j]=M[j];
        }

        /*printf("修改後\n");
        for(k=1 ; k<SIZE ; k++){
            printf("%d %d %d\n", L[k], R[k], M[k]);
        }printf("\n");*/
    }

    for(i=1 ; i<SIZE ; i++){
        printf("%d", M[i]);

    }


    return 0;
}
