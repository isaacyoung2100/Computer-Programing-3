#include <stdio.h>
#include <stdlib.h>
int sum=0;
int diagnose(char g[3][4], int row, int col)
{
    int i,j;

    printf("row= %d  ",row);
    for(i=0 ; i<=col ; i++)
    {
        if(g[row][i]=='x')
            sum++;
        if(g[row][i]=='o')
            sum--;
    }
    if(row==0)
    {
        if(sum==0||sum==1)
            return 1;
        else
            return 0;
    }

    return diagnose(g, --row, col);
}
int main()
{
    int i, j;
    char game[3][4];

    for(i=0 ; i<3 ; i++)
    {
        for(j=0 ; j<4 ; j++)
        {
            scanf("%c", &game[i][j]);
        }
    }
    /*printf("\n");
    for(i=0 ; i<3 ; i++){
     for(j=0 ; j<3 ; j++){
         printf("%c", game[i][j]);
     }printf("\n");
    }*/
    if(diagnose(game,2,2))
        printf("Yes.");
    else
        printf("No.");

    return 0;
}
