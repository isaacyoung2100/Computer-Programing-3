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
/*int max(int cc, int r, int c, int *p, int m[][cc], int *biggest)
{
    printf("%d, ", m[r][c]);
    (*p)+=m[r][c];
    printf("*p= %d\n", *p);

    if(r==0 && c==0){
        if(*p>=*biggest)
            *biggest=*p;
        return  *p-=m[0][0];
    }
    if(r-1>=0){
        max(cc, r-1, c, p, m, biggest);

    }
    if(c-1>=0){
        max(cc, r, c-1, p, m, biggest);
    }
    *p-=m[r][c];
    printf("%d\n", *p);
}*/
int main()
{
    int rows, colums;
    int i, j;
    printf("N?M?");
    scanf("%d %d", &rows, &colums);
    int rr=rows, cc=colums;

    int map[rows][colums];
    int way[rows][colums];

    srand(time(NULL));

    for(i=0 ; i<rows ; i++)
        for(j=0 ; j<colums ; j++){
            map[i][j]=rand()%100+0;
            way[i][j]=0;
        }
    way[rows-1][colums-1]=1;
    display(rows, colums, map);

    int ans=0, maxx=0;
//    max(cc, rows-1, colums-1, &ans, map, &maxx);
//    printf("max= %d\n", maxx);


    for(i=1 ; i<colums ; i++)
        map[0][i]+=map[0][i-1];
    for(i=1 ; i<rows ; i++)
        map[i][0]+=map[i-1][0];

    for(i=1 ; i<rows ; i++)
    {
        for(j=1 ; j<colums ; j++)
        {
            if(map[i][j-1]>=map[i-1][j]){//left is bigger
                map[i][j]+=map[i][j-1];
            }
            else
                map[i][j]+=map[i-1][j];
        }
    }
    display(rows , colums, map);

    for(i=rows-1 ; i>=0 ; i--){
        for(j=colums-1 ; j>=0 ; j--){
            if(way[i][j]==1)
            {
                if(i==0)//on first row
                    way[i][j-1]=1;
                else if(j==0)
                    way[i-1][j]=1;
                else if(map[i][j-1]>=map[i-1][j])//left is bigger
                    way[i][j-1]=1;
                else
                    way[i-1][j]=1;
            }
        }
    }
    display(rows, colums, way);


    return 0;
}
