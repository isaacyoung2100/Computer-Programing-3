#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char name[20];
    int month;
    int day;
}file;
int main()
{
    int num;
    printf("num?\n");
    scanf("%d", &num);

    file students[num];
    for(int i=0 ; i<num ; i++){
        scanf("%s", &students[i].name);
        scanf("%d", &students[i].month);
        scanf("%d", &students[i].day);
    }

    for(int j=0 ; j<num-1 ; j++){
        for(int i=0 ; i<num-1 ; i++){
            file temp;
            if(students[i].month>students[i+1].month){//年紀比較小
                printf("a");
                temp=students[i];
                students[i]=students[i+1];
                students[i+1]=temp;
            }
            else if(students[i].month==students[i+1].month){//月份相同
                if(students[i].day>students[i+1].day){
                    printf("b");
                    temp=students[i];
                    students[i]=students[i+1];
                    students[i+1]=temp;
                }
            }
        }
    }

    for(int i=0 ; i<num ; i++){
        printf("%s", students[i].name);
        printf(" %d", students[i].month);
        printf(" %d\n", students[i].day);
    }
    return 0;
}


