#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
    char str[81];
    struct node *next;
}Node;
int main()
{
    char a[81];
    scanf("%s", a);

    int len;
    len = strlen(a);

    Node *headPtr, *newPtr;
    headPtr = newPtr = NULL;
    for(int i = len - 1 ; i>=0 ; i--)
    {
        if(a[i]>='A' && a[i]<='Z'){
            newPtr = (Node *)malloc(sizeof(Node));

            newPtr->str[0] = a[i];
            newPtr->str[1] = '\0';

            newPtr->next = headPtr;
            headPtr = newPtr;
        }
        else{
            newPtr = (Node *)malloc(sizeof(Node));

            strcpy(newPtr->str, headPtr->str);
            strcat(newPtr->str, headPtr->next->str);
            headPtr=headPtr->next->next;

            switch(a[i])
            {
                case '+':   strcat(newPtr->str, "+");break;
                case '-':   strcat(newPtr->str, "-");break;
                case '*':   strcat(newPtr->str, "*");break;
                case '/':   strcat(newPtr->str, "/");break;
            }

            newPtr->next = headPtr;
            headPtr = newPtr;
        }
    }

    printf("%s", headPtr->str);
    return 0;
}
