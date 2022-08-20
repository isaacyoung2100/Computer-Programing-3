#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    int n, k;
    scanf("%d %d", &n, &k);//n=6, k=3

    int arr[n+1][k+1];//arr[7][4]

    for(i=0 ; i<=n ; i++)//i:0 1 2 3 4 5 6
        for(j=0 ; j<=k ; j++)//j:0 1 2 3
            if(i==j ||  j==0)
                arr[i][j]=1;
            else if(i < j)
                arr[i][j]=0;
            else
                arr[i][j]=arr[i-1][j]+arr[i-1][j-1];
    for(j=0 ; j<=k ; j++){
        for(i=0 ; i<=n ; i++){
            printf("%10d", arr[i][j]);
        }printf("\n");
    }

    printf("%d", arr[n][k]);

    return 0;
}
