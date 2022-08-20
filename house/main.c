#include <stdio.h>
#include <stdlib.h>
void display(int rows, int colums, int m[][colums])
{
    int i, j;
    for(i=0 ; i<rows ; i++){
        for(j=0 ; j<colums ; j++){
            printf("%2d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main()
{
    int N, M;
    int i, j;
    printf("N?M?");
    scanf("%d %d", &N, &M);

    int lend[N][M];

    srand(time(NULL));

    for(i=0 ; i<N ; i++)
        for(j=0 ; j<M ; j++)
            lend[i][j]=rand()%2+0;
    //display(N, M, lend);
    int Maxlength=0, length=2;
    int sum=0;
    int k, d;

    for(i=0 ; i<N ; i++)
    {
        for(j=0 ; j<M ; j++)
        {
            if(lend[i][j]==0)//if that project is zero
            {
                while(1)
                {
                    for(k=0 ; k<length ; k++){
                        for(d=0 ; d<length ; d++){
                            sum+=lend[i+k][j+d];
                        }
                    }
                    if(sum!=0)  break;
                    length++;
                }
                if(length-1>Maxlength)    Maxlength=length-1;
                sum=0;
                length=2;
            }
        }
    }

    printf("%d\n", Maxlength*Maxlength);


    return 0;
}
