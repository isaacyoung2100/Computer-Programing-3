#include <stdio.h>
#include <stdlib.h>
int ca(char input[], int left, int right){
    int i;
    int operatorSum = 0; // '+', '-', '*'....
    int operandSum = 0;  // '0 ~ 9'.....
    int flag = 0;
    int a, b;
//input[left]是數字字元
    if(input[left] >= '0' && input[left] <= '9'){ // 字串轉整數
        int sum = 0;

        for(i = left; i <= right; i++){
            sum *= 10;
            sum += (input[i] - '0');
        }
        return sum;
    }
    else {           // 遞迴

        for(i = left; i < right; i++){//0至8
       //數字
            if(input[i] >= '0' && input[i] <= '9'){//如果它是數字
                if(flag == 0)
                    operandSum++;//運算元(數字)加一

                    flag = 1;
            }
           //空格
            else if(input[i] == ' '){//如果它是空格
                flag = 0;
            }
           //運算子
            else{//如果它是加號或是乘號
                operatorSum++;//運算子(加乘)加一
            }

            if(operandSum == operatorSum && flag == 0)
                break;
            }

            a = ca(input, left+2, i-1);
            b = ca(input, i+1, right);

            if(input[left] == '+')
                return a + b;
            if(input[left] == '*')
                return a * b;
    }
}

int main(){
    int size, i;

    scanf("%d",&size);
    fflush(stdin);

    char input[size];

    for(i = 0; i < size; i++)
    scanf("%c", &input[i]);
    fflush(stdin);

    printf("%d\n",ca(input, 0, size - 1));

    return 0;
}
