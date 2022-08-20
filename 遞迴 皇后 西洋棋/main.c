#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*void show(char a[][9], int n, int col)
{
    int i=0, j;
    for(i=0 ; i<=n ; i++){
        if(a[col][i]=='X')
    }
}*/
int main()
{
    char chess[9][9];
    int i, j;

    for(i=0 ; i<9 ; i++){
        for(j=0 ; j<9 ; j++){
            chess[i][j]='X';
            printf("%c", chess[i][j]);
        }
        printf("\n");
    }

    show(chess, 8, 0);
    return 0;
}
