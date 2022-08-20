#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char ID[11];
    char Name[20];
    int Score[4];
    char Lastname[10];
}file;

void display(file student[], int num)
{
    int i, j;
    for(i=0 ; i<num ; i++){
        printf("%s ", student[i].ID);
        printf("%s ", student[i].Name);

        for(j=0 ; j<4 ; j++)
            printf("%d ", student[i].Score[j]);
        printf("\n");
    }
    printf("\n");
}
int mycomparion(char a[], char b[], int n)//a¬O§_¤p©ób
{
    for(int i=0 ; i<n ; i++){
        printf("%d", i);
        printf("%d\n", a[i]-b[i]);
        if( a[i] - b[i] < 0 ){
            printf("a: %c, b: %c\n", a[i], b[i]);
            printf("%d\n", a[i]-b[i]);
            return 1;
        }
    }
    return 0;
}
void IDsort(file a[],int left,int right)
{
    int i,j;
    char pivot[11];
    if(left>=right) return;

    i=left; j=right+1;
    for(int k=0 ; k<11 ; k++)
        pivot[k]=a[left].ID[k];

    do{
        int k=0, d=0;
        do{
            i++;
        }while(mycomparion(a[i].ID, pivot, 11) && i<right);
        printf("i= %d\n", i);

        do{
            j--;
        }while(mycomparion(pivot, a[j].ID, 11) && j>left);
        printf("j= %d\n", j);

        if(i<j){
            file temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);

    file temp=a[j];
    a[j]=a[left];
    a[left]=temp;

    IDsort(a,left,j-1);
    IDsort(a,j+1,right);

    return;

}
/*void Namesort(file a[],int left,int right)
{
    int i,j;
    char pivot[10];
    if(left>=right) return;

    i=left; j=right+1;
    for(int k=0 ; k<11 ; k++)
        pivot[k]=a[left].Lastname[k];

    do{
        int k=0, d=0;
        do{
            i++;
        }while(mycomparion(a[i].Lastname, pivot, 10) && i<right);
        printf("i= %d\n", i);

        do{
            j--;
        }while(mycomparion(pivot, a[j].Lastname, 10) && j>left);
        printf("j= %d\n", j);

        if(i<j){
            file temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);

    file temp=a[j];
    a[j]=a[left];
    a[left]=temp;

    Namesort(a,left,j-1);
    Namesort(a,j+1,right);

    return;

}*/
int main()
{
    int num, i, j;
    scanf("%d\n", &num);

    file student[num];
    for(i=0 ; i<num ; i++){
        char temp[10]={' '};
        scanf("%s", student[i].ID);

        scanf("%s", student[i].Name);
        scanf("%s", student[i].Lastname);
        strcat(student[i].Name, strcat(temp, student[i].Lastname));

        for(j=0 ; j<4 ; j++)
            scanf("%d", &student[i].Score[j]);

    }


    printf("Order: ID\n");
    IDsort(student, 0, num-1);
    display(student, num);

    /*printf("Order: Last Name\n");
    Namesort(student, 0,
              num-1);
    display(student, num);*/

    return 0;
}
/*first sort the input by ID, then by Last Name, by test score one, by test score two, by test score
three, and finally by test score four, all into non-decreasing order.

*/
