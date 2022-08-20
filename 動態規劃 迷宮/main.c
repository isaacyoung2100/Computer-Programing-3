#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int x, y;
    struct node *from;
    struct node *next;
}Node;
int main()
{
    int N, M;
    printf("迷宮大小: \n");
    scanf("%d %d", &N, &M);
    fflush(stdin);

    int i, j;
    char maze[N][M];
    for(i=0 ; i<N ; i++){
        for(j=0 ; j<M ; j++){
            scanf("%c", &maze[i][j]);
        }fflush(stdin);
    }

    Node *currentPtr, *tailPtr, *newPtr;
    currentPtr = (Node *)malloc(sizeof(Node));
    currentPtr->x = currentPtr->y = 0;
    currentPtr->from = currentPtr->next = NULL;
    tailPtr = currentPtr;

    int x, y;
    while(1)
    {
        //判斷點座標
        x = currentPtr->x;
        y = currentPtr->y;

        if(x == N-1 && y == M-1)
            break;

        maze[x][y] = '1';


        if( y - 1 >= 0 && maze[x][y-1]=='0'){//上
            newPtr = (Node *)malloc(sizeof(Node));

            newPtr->x = x;
            newPtr->y = y-1;

            tailPtr->next = newPtr;
            newPtr->from = currentPtr;
            newPtr->next = NULL;
            tailPtr = newPtr;
        }
        if( y < N && maze[x][y+1]=='0'){//下
            newPtr = (Node *)malloc(sizeof(Node));

            newPtr->x = x;
            newPtr->y = y+1;

            tailPtr->next = newPtr;
            newPtr->from = currentPtr;
            newPtr->next = NULL;
            tailPtr = newPtr;
        }
        if( x - 1 >= 0 && maze[x-1][y]=='0'){//左
            newPtr = (Node *)malloc(sizeof(Node));

            newPtr->x = x-1;
            newPtr->y = y;

            tailPtr->next = newPtr;
            newPtr->from = currentPtr;
            newPtr->next = NULL;
            tailPtr = newPtr;
        }
        if( y < M && maze[x+1][y]=='0'){//右
            newPtr = (Node *)malloc(sizeof(Node));

            newPtr->x = x+1;
            newPtr->y = y;

            tailPtr->next = newPtr;
            newPtr->from = currentPtr;
            newPtr->next = NULL;
            tailPtr = newPtr;
        }

        currentPtr = currentPtr->next;
    }

    while(currentPtr){
        printf("%d %d\n", currentPtr->x, currentPtr->y);
        currentPtr = currentPtr->from;
    }

    return 0;
}
//headptr, currentPtr, newPtr, NULL
/*
3 4
0001
0100
1100
*/
//可以印出更多路徑嗎 不行 注意路徑接哪裡
//寫程式學習日誌
