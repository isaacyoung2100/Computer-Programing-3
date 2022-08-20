#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
    char str[80];
    char temp[80];
    struct node *next;
    struct node *last;
};
int main()
{
    struct node *first, *current, *previous, *bottem;
    int i=0;
    char arr[81], ch;
    printf("請輸入您要轉換的前序字串:\n");

    for(;;i++){
        current = malloc( sizeof(struct node) );//請求一塊足夠大小的記憶體空間
        ch=getche();
        if(ch == ' '){
            free(current);
            break;
        }
        else{
            current->str[0] = ch;
            current->str[1] = '\0';
        }

        if(i==0){
            first = current;//如果第一輪的話,將first指向現在這個
            current->last = first;
        }
        else{
            previous->next = current;//和前一項連起來
            current->last = previous;
        }
        current->next = NULL;//將此項的箭頭先指到NULL
        previous = current;//把此項變為前項
        bottem = previous;
    }
    current = bottem;

    printf("\n");
    while(1){
        printf("%s", current->str);
        if(current == first)
            break;
        current = current->last;

    }
    return 0;
}
/*
*+AB-CD
*/
