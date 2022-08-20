#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int power[10];
    int coeffient[10];
    int length;
}polynomials;

void display(polynomials a[], polynomials b[], int n)
{
    printf("\n");
    int i, j;
    for(i=0 ; i<n ; i++){

        for(j=0 ; j<a[i].length ; j++)
            printf("%d ", a[i].power[j]); printf("\n");
        for(j=0 ; j<a[i].length ; j++)
            printf("%d ", a[i].coeffient[j]); printf("\n");

        for(j=0 ; j<a[i].length ; j++)
            printf("%d ", b[i].power[j]); printf("\n");
        for(j=0 ; j<a[i].length ; j++)
            printf("%d ", b[i].coeffient[j]); printf("\n");
    }
    printf("\n");
}
polynomials calculatequortient(polynomials, polynomials, polynomials*, polynomials*);
int main()
{
    int n;
    printf("請問您要輸入幾筆資料?");
    scanf("%d", &n);

    polynomials dividend[n];
    polynomials divisor[n];

    int i, j=0, ch, q, k, d;
    for(i=0 ; i<n ; i++){
        do{ scanf("%d", &dividend[i].power[j++]); }while(ch=getchar()!='\n');j=0;
        do{ scanf("%d", &dividend[i].coeffient[j++]); }while(ch=getchar()!='\n');
        dividend[i].length=j;j=0;
        do{ scanf("%d", &divisor[i].power[j++]); }while(ch=getchar()!='\n');j=0;
        do{ scanf("%d", &divisor[i].coeffient[j++]); }while(ch=getchar()!='\n');
        divisor[i].length=j;j=0;
    }
    display(dividend, divisor, n);

    polynomials renewdiviend[n], renewdivisor[n], quortient[n], reminder[n];
    for(i=0 ; i<n ; i++){
        int initial=dividend[i].power[0];//紀錄最高次方
        k=0;
        for(j=0 ; j<dividend[i].length ; j++){//檢查被除數次方向的遺漏
            if(j!=0 && dividend[i].power[j]!=(--initial))//如果這次方數字不事前一項小一的話
                renewdiviend[i].coeffient[k++]=0;
            renewdiviend[i].coeffient[k++]=dividend[i].coeffient[j];//將係數複製到新陣列
        }renewdiviend[i].length=k;
        initial=divisor[i].power[0];//紀錄最高次方
        k=0;
        for(j=0 ; j<divisor[i].length ; j++){//檢查被除數次方向的遺漏
            if(j!=0 && divisor[i].power[j]!=(--initial))//如果這次方數字不事前一項小一的話
                renewdivisor[i].coeffient[k++]=0;
            renewdivisor[i].coeffient[k++]=divisor[i].coeffient[j];//將係數複製到新陣列
        }renewdivisor[i].length=k;
        //quortient
        if(renewdivisor[i].length>renewdiviend[i].length){//當除式最高次方大於被除式
            quortient[i].length=1;quortient[i].coeffient[0]=0;quortient[i].power[0]=0;
        }else
            renewdiviend[i]=calculatequortient(renewdiviend[i], renewdivisor[i], &quortient[i], &reminder[i]);

        int ini=renewdiviend[i].length-(renewdivisor[i].length-1);//被廚式檢查開始項
        reminder[i].length=renewdivisor[i].length-1;

        for(j=0, q=ini ,d=reminder[i].length-1; q<renewdiviend[i].length ; j++, q++, d--){
            if(renewdiviend[i].coeffient[q]==0){//細數為零
                j--;
                reminder[i].length--;
                continue;
            }
            else{
                reminder[i].coeffient[j]=renewdiviend[i].coeffient[q];
                reminder[i].power[j]=d;
            }
        }
        if(reminder[i].length==0){
            reminder[i].length=1;reminder[i].coeffient[0]=0;reminder[i].power[0]=0;
        }
    }
    display(quortient, reminder, n);
    return 0;
}

polynomials calculatequortient(polynomials dividend, polynomials divisor, polynomials *quiotient, polynomials *reminider)//a is dividend, b is divisor
{

    int i, j=0, d, k, l;
    polynomials temp=divisor;
    quiotient->length=0;
    int inipower=dividend.length-divisor.length;
    for(i=divisor.length, d=0, l=0; i<=dividend.length ; i++, d++, l++){//最多除幾次
    //d=3, l=2
        if(dividend.coeffient[d]==0){
            quiotient->power[d]=inipower--;
            l--;
            continue;
        }
        quiotient->power[l]=inipower--;
        quiotient->coeffient[l]=dividend.coeffient[d]/divisor.coeffient[0];//商: 倍數
        quiotient->length++;

        for(j=0 ; j<divisor.length ; j++)//計算temp
           temp.coeffient[j]=divisor.coeffient[j]*quiotient->coeffient[l];

        for(k=0 ; k<divisor.length ; k++)//substract
            dividend.coeffient[k+d]-=temp.coeffient[k];
    }
    return dividend;
}


/*
1
1 0
1 1
2 0
1 3

1
3 2 0
6 -5 -7
2 1 0
1 -2 1

2
1 0
1 1
2 0
1 3
3 2 0
6 -5 -7
2 1 0
1 -2 1

1
5 4 3 2 1 0
6 19 20 8 2 1
2 1 0
1 2 1



*/

 /*int ini=dividend.length-(divisor.length-1);//被廚式檢查開始項
    reminider->length=divisor.length-1;

    printf("%d\n", reminider->length);
    printf("%d to %d\n", ini, dividend.length-1);
    for(j=0, q=ini ,d=reminider->length-1; q<dividend.length ; j++, q++, d--){
        if(dividend.coeffient[q]==0){//細數為零
            j--;
            reminider->length--;
            continue;
        }
        else{

            reminider->coeffient[j]=dividend.coeffient[q];
            reminider->power[j]=d;
        }
    }

    if(reminider->length==0){
        reminider->length=1;
        reminider->coeffient[0]=0;
        reminider->power[0]=0;
    }

    for(i=0 ; i<reminider->length ; i++)
        printf("%d ", reminider->coeffient[i]);
    printf("\n");
    for(i=0 ; i<reminider->length ; i++)
        printf("%d ", reminider->power[i]);
    printf("\npowerlength: %d", reminider->length);*/
