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
    printf("�п�J�z�n�ഫ���e�Ǧr��:\n");

    for(;;i++){
        current = malloc( sizeof(struct node) );//�ШD�@�������j�p���O����Ŷ�
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
            first = current;//�p�G�Ĥ@������,�Nfirst���V�{�b�o��
            current->last = first;
        }
        else{
            previous->next = current;//�M�e�@���s�_��
            current->last = previous;
        }
        current->next = NULL;//�N�������b�Y������NULL
        previous = current;//�⦹���ܬ��e��
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
