#include <stdio.h>
#include <stdlib.h>

int min(int a,int b){
 return a < b ? a : b;
}

int main(){

    int i,j, MAX;

    printf("����Τg�a�j�p:");
    scanf("%d", &MAX);
    int array[MAX][MAX];
    int dp[MAX][MAX];


    for(i = 0; i < MAX; i++)
        for(j = 0; j < MAX; j++)
            array[i][j] = rand() % 2;

    for(i = 0; i < MAX; i++){
        for(j = 0; j < MAX; j++){
            printf("%d ",array[i][j]);
        }printf("\n");
    }

    for(i = 0; i < MAX; i++)
        dp[0][i] = (array[0][i] == 1 ? 0 : 1);

    for(i = 0; i < MAX; i++)
        dp[i][0] = (array[i][0] == 1 ? 0 : 1);

    int max = 0;
    for(i = 1; i < MAX; i++){
        for(j = 1; j < MAX; j++){
            //�W ���W �� �䤤�̤j���[�@ �x�s�bdp��
            dp[i][j] = min(dp[i-1][j],min(dp[i][j-1], dp[i-1][j-1])) + 1;
            //��map�W�o��O���𪺸� �������ܦ�0
            if(array[i][j] == 1)
                dp[i][j] = 0;

            if(dp[i][j] > max)
                max = dp[i][j];
        }
    }

    printf("%d\n", max);
    return 0;
}

/*
array   dp
00000   11111
01000   10122
01000   10123
01100   10012
11111   00000*/
