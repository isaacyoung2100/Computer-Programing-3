#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int min(int a, int b){
    return a<b ? a : b;
}
int main()
{
    int longA=0, longB=0;
    int ch;
    char strA[20], strB[20];

    scanf("%s", strA);
    scanf("%s", strB);
    longA = strlen(strA);
    longB = strlen(strB);

    printf("strA: %s, length= %d\n", strA, longA);
    printf("strB: %s, length= %d\n", strB, longB);


    int cul[longA+1][longB+1], i, j;
    for(i=0, j=0 ; j<=longA ; j++)
        cul[i][j]=j;
    for(i=0 , j=0 ; i<=longB ; i++)
        cul[i][j]=i;

    for(i=1 ; i<=longB ; i++){
        for(j=1 ; j<=longA ; j++){
            if(strA[i-1] == strB[j-1])
                cul[i][j] = min(cul[i-1][j-1], min(cul[i-1][j], cul[i][j-1]));
            else
                cul[i][j] = min(cul[i-1][j-1], min(cul[i-1][j], cul[i][j-1]))+1;
        }
    }

    for(i=0 ; i<=longA ; i++){
        for(j=0 ; j<=longB ; j++){
            printf("%d ", cul[i][j]);
        }printf("\n");
    }

    printf("Minimum steps: %d", cul[longA][longB]);
    return 0;
}
