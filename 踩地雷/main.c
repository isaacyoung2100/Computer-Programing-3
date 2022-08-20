#include <stdio.h>
#include <stdlib.h>

int main()
{
     int main(){
    int size[100][2];
    char position[100][100][100];
    int i=0, j, k, round=0;

    while(1){
        int rows, cols;
        scanf("%d %d", &rows, &cols);

        if(rows==0 && cols==0)
            break;
        size[round][0]=rows;
        size[round][1]=cols;
        fflush(stdin);
        for(i=0 ; i<rows ; i++){
            for(j=0 ; j<cols ; j++){
                scanf("%c", &position[round][i][j]);

            }fflush(stdin);
        }

        round++;
    }

    int ans[round][100][100];
    for(i=0 ; i<round ; i++){//初始化數字圖
        for(j=0 ; j<size[i][0] ; j++){
            for(k=0 ; k<size[i][1] ; k++){
                if(position[i][j][k]=='.')
                    ans[i][j][k]=0;
                else
                    ans[i][j][k]=1;
            }
        }
    }


     for(i=0 ; i<round ; i++){//數字圖運算
        for(j=0 ; j<size[i][0] ; j++){
            for(k=0 ; k<size[i][1] ; k++){
                if(position[i][j][k]=='*'){
                    ans[i][j-1][k-1]+=1;ans[i][j-1][k]+=1;ans[i][j-1][k+1]+=1;
                    ans[i][j][k-1]+=1;ans[i][j][k+1]+=1;
                    ans[i][j+1][k-1]+=1;ans[i][j+1][k]+=1;ans[i][j+1][k+1]+=1;
                }
            }
        }
    }

    for(i=0 ; i<round ; i++){
        printf("#%d\n", i+1);
        for(j=0 ; j<size[i][0] ; j++){
            for(k=0 ; k<size[i][1] ; k++){
                printf("%d", ans[i][j][k]);
            }printf("\n");
        }
    }


 }
 /*
4 4
*...
....
..*.
....
3 5
....*
.....
*....
0 0

1100 1000
1211 0000
0111 0010
0111 0000
 */

}
