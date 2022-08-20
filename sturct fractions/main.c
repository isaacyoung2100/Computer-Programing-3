#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int integer;
    int numerator;
    int denominator;
}fractions;
void simplify(int *inte, int *nume, int *deno)
{
    int i;
    for(i=1 ; i<*nume ; i++){
       if(*nume%i==0  && *deno%i==0){
            *nume/=i;
            *deno/=i;
       }
    }
    *inte=*nume/(*deno);
    *nume-=*inte*(*deno);
}
int main()
{
    int num;
    printf("How many fractions do you want to input?");
    scanf("%d", &num);

    int i, j;
    fractions data[num];
    for(i=0 ; i<num ; i++){
        printf("%d.\n", i+1);
        printf("integral part:");
        scanf("%d", &data[i].integer);

        printf("numerator part:");
        scanf("%d", &data[i].numerator);

        printf("denominator part:");
        scanf("%d", &data[i].denominator);
    }
    //換假分數
    for(i=0 ; i<num ; i++){
        if(data[i].integer>0)
            data[i].numerator+=data[i].integer*data[i].denominator;
        else if(data[i].integer<0)
            data[i].numerator=data[i].integer*data[i].denominator-data[i].numerator;
        printf("%d\n", data[i].numerator);
    }
    //找分母
    int findenominator=1;
    for(i=0 ; i<num ; i++){
        findenominator*=data[i].denominator;
    }
    //分子通分+加總
    int sum=0;
    for(i=0 ; i<num ; i++){
        data[i].numerator*=(findenominator/data[i].denominator);
        printf("%d\n", data[i].numerator);
        sum+=data[i].numerator;
    }
    printf("check= %d, %d\n", sum, findenominator);
    int integer, denominators[num];
    for(i=0 ; i<num ; i++)
        denominators[i]=data[i].denominator;

    int sum1=sum, findenominator1=findenominator*num;
    simplify(&integer, &sum, &findenominator);
    printf("Sum\n= %d, %d/%d\n", integer, sum, findenominator);
    simplify(&integer, &sum1, &findenominator1);
    printf("Average\n= %d, %d/%d\n", integer, sum1, findenominator1);


    return 0;
}
