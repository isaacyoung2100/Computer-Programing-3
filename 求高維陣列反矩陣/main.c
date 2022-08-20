#include <stdio.h>
#include <stdlib.h>
#define SIZE 8
void show(double a[][SIZE], double b[][SIZE])
{
    int i, j;
    printf("MATRIX AND INVERSED MATRIX\n");
    for(i=0 ; i<SIZE ; i++){
        for(j=0 ; j<SIZE ; j++){
            printf("%8.3f ",a[i][j]);
        }
        printf("    ");
        for(j=0 ; j<SIZE ; j++){
            printf("%8.3f ",b[i][j]);
        }

    printf("\n");
    }
    printf("\n");

}
int main()
{
    int i, j, k, d, temp=0;
    double matrix[SIZE][SIZE];
    double ans[SIZE][SIZE];
    double check[SIZE][SIZE];
    int flagi=0, flagj=0;
    double multiple;

    for(i=0 ; i<SIZE ; i++){
        for(j=0 ; j<SIZE ; j++){
            matrix[i][j]=rand()%50;

            if(i==j)
                ans[i][j]=1;
            else
                ans[i][j]=0;
        }
    }
    printf("Original:\n");
    show(matrix, ans);//印初始矩陣
    //修改初始矩陣，因為標記項有可能不適0
    for(i=0 ; i<SIZE ; i++)
    {
        for(j=0 ; j<SIZE ; j++)
        {
            if(i==j)//檢查標記項
            {
                if(matrix[i][j]==0)//如果標記項是0的話
                {
                    for(temp=0 ; temp<SIZE ; temp++)
                    {
                        if(matrix[temp][j]!=0)
                        {
                           for(k=0 ; k<SIZE ; k++)
                            {
                                matrix[j][k]+=matrix[temp][k];
                            }
                        }
                        if(matrix[temp][j]!=0)
                            break;
                    }
                }
            }
        }
    }
    printf("After modified:\n");
    show(matrix, ans);//印修改後矩陣
    for(i=0 ; i<SIZE ; i++)
        for(j=0 ; j<SIZE ; j++)
            check[i][j]=matrix[i][j];
    //將矩陣改為上三角
    for(flagi=0, flagj=0; flagi<SIZE && flagj<SIZE; flagi++, flagj++)
    {
        for(i=flagi ; i<SIZE ; i++)//第0到第3列
        {
            if(i==flagi)//頭一行
            {
                if(matrix[flagi][flagj]!=1)//如果基準項不為1
                {
                    //printf("matrix[%d][%d]: %lf\n", flagi, flagj,matrix[flagi][flagj]);
                    multiple=matrix[flagi][flagj];
                    //printf("倍數: %f\n", multiple);
                    for(j=0 ; j<SIZE ; j++)
                    {
                        matrix[i][j]/=multiple;
                        ans[i][j]/=multiple;
                    }
                    //show(matrix, ans);
                }
            }
            else
            {
                if(matrix[i][flagj]!=0)//如果基準項下面的項目不為零
                {
                    //printf("matrix[%d][%d]: %lf\n", i, flagj,matrix[i][flagj]);
                    multiple=matrix[i][flagj];
                    //printf("倍數: %f\n", multiple);
                    //printf("將扣之值: ");
                    for(j=flagj ; j<SIZE ; j++)
                    {
                        matrix[i][j]-=(matrix[flagi][j]*multiple);
                        //printf("%f ", matrix[flagi][j]*multiple);
                        //ans[i][j]-=(ans[flagi][j]*multiple);
                    }//printf("\n");
                    for(j = 0 ; j < SIZE ; j ++)
                        ans[i][j]-=(ans[flagi][j]*multiple);
                }
                //show(matrix, ans);
            }
        }
    }
    printf("上三角矩陣: ");
    show(matrix, ans);
    flagi=flagj=0;
    int copyi;
    //
    for(i=0, j=0 ; i<SIZE && j<SIZE ; i++, j++)
    {
        //printf("%d%d: \n", i, j);//i=2, j=2
        flagi=i;//flagi=2;
        for(d=i ; d>0 ; d--)//d是列數的變換, 從標記列跑回第一列//d=2
        {
            //show(matrix, ans);
            if(matrix[d-1][j]!=0)//從標記項的上一個開始檢查
            {
                multiple=matrix[d-1][j];
                //printf("matrix[%d][%d]= %f\n", d-1, j, matrix[d-1][j]);
                //printf("倍數: %f\n", multiple);
                for(k=j ; k<SIZE ; k++)//k是行數的變換
                {
                    matrix[d-1][k]-=(matrix[flagi][k]*multiple);
                }
                for(k=0 ; k<SIZE ; k++)//k: 0~4
                {
                    ans[d-1][k]-=(ans[flagi][k]*multiple);
                }
                //printf("diminish   -     -      -\n");
            }
            //show(matrix, ans);
        }

    }

    printf("Validation 1\n");
    show(matrix, ans);

    float validate[SIZE][SIZE]={0};
    printf("Validation 2\n");
    printf("MATRIX-----------------------------\n");
    for(i=0 ; i<SIZE ; i++){
        for(j=0 ; j<SIZE ; j++){
            printf("%8.3f ",check[i][j]);
        }
        printf("\n");
    }
    printf("INVERSE MATRIX-----------------------\n");
    for(i=0 ; i<SIZE ; i++){
        for(j=0 ; j<SIZE ; j++){
            printf("%8.3f ",ans[i][j]);
        }
        printf("\n");
    }


    for(k = 0 ; k < SIZE ; k ++)
        for(i = 0 ; i < SIZE ; i ++){
            for(j = 0 ; j < SIZE ; j ++){
                validate[k][i] = validate[k][i] + check[k][j] * ans[j][i];
                //printf("%d%d = %d%d + %d%d * %d%d\n", k, i, k, i, k, j, j, i);
            }
        }

    printf("VALID MATRIX------------------------\n");
    for(i = 0 ; i < SIZE ; i++){
        for(j = 0 ; j < SIZE ; j++){
            printf("%8.3f ", validate[i][j]);
        }printf("\n");
    }


    return 0;
}


