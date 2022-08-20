#include <stdio.h>
#include <stdlib.h>
typedef struct{
    float x;
    float y;
}plane;

float calculate(plane a, plane b, plane c)
{
    float area;
    area=(a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y))/2;

    printf("a: %f\n", area);
    return area > 0 ? area : (-area);
}
int main()
{
    int n;
    scanf("%d", &n);

    int i;
    plane points[n];
    for(i=0 ; i<n ; i++){
        scanf("%f", &points[i].x);
        scanf("%f", &points[i].y);
    }

    float sum=0;
    for(i=0 ; i<n-2 ; i++){
        sum+=calculate(points[0], points[i+1], points[i+2]);
    }

    printf("%f", sum);


    return 0;
}
