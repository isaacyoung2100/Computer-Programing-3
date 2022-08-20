#include <stdio.h>
#include <stdlib.h>
//知道要算勝率，但不會算
//不知道要怎麼贏
void winchance(int A,int B,int C,int player,int *w,int *t)
{
    int i;
    if(A==0&&B==0&&C==0){
        (*t)++;

        if(player%2==1)
            (*w)++;
    }

    for(i=1 ; i<=2&&A-i>=0 ; i++)
        winchance(A-i,B,C,++player,w,t);
    for(i=1 ; i<=2&&B-i>=0 ; i++)
        winchance(A,B-i,C,++player,w,t);
    for(i=1 ; i<=2&&C-i>=0 ; i++)
        winchance(A,B,C-i,++player,w,t);

}
int main()
{
    int A,B,C;
    int player=0;
    int choice,i;
    float MaxChance=-1, accuracy;
    int which=0, howmaney=0;
    int total,wins;

    printf("a堆數:");scanf("%d", &A);
    printf("b堆數:");scanf("%d", &B);
    printf("c堆數:");scanf("%d", &C);
    printf("\n");

    while(1){

        if(player%2==0){
            printf("請取: \n");
            scanf("%d %d", &choice, &i);

            if(choice==1)   A-=i;
            if(choice==2)   B-=i;
            if(choice==3)   C-=i;

            printf("取後: A: %d,B: %d,C: %d\n\n",A,B,C);

            if(A==0&&B==0&&C==0){
                printf("You win!");
                return 0;
            }

        }
        else{
            MaxChance=0;
            for(i=1 ; i<=2&&A-i>=0 ; i++){
                total=wins=0;
                winchance(A-i,B,C,1,&wins,&total);
                printf("%d, %d\n", wins, total);
                accuracy=(double)wins/total;

                if(accuracy>MaxChance){
                    MaxChance=accuracy;
                    which=1;
                    howmaney=i;
                }
                printf("1: %d\n", i);
                printf("%lf\n", accuracy);
                printf("Max= %f\n", MaxChance);
            }

            for(i=1 ; i<=2&&B-i>=0 ; i++){
                total=wins=0;
                winchance(A,B-i,C,1,&wins,&total);
                accuracy=(double)wins/total;

                if(accuracy>MaxChance){
                    MaxChance=accuracy;
                    which=2;
                    howmaney=i;
                }
                printf("2: %d\n", i);
                printf("%lf\n", accuracy);
                printf("Max= %f\n", MaxChance);
            }


            for(i=1 ; i<=2&&C-i>=0 ; i++){
                total=wins=0;
                winchance(A,B,C-i,1,&wins,&total);
                accuracy=(double)wins/total;

                if(accuracy>MaxChance){
                    MaxChance=accuracy;
                    which=3;
                    howmaney=i;
                }
                printf("3: %d\n", i);
                printf("%lf\n", accuracy);
                printf("Max= %f\n", MaxChance);
            }

            if(which==1)    A-=howmaney;
            if(which==2)    B-=howmaney;
            if(which==3)    C-=howmaney;

            printf("電腦取後: A: %d,B: %d,C: %d\n\n",A,B,C);

            if(A==0&&B==0&&C==0){
                printf("Computer win!");
                return 0;
            }
        }

        player++;
    }
    return 0;
}
