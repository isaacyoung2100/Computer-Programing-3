#include <stdio.h>
#include <stdlib.h>
int ca(char input[], int left, int right){
    int i;
    int operatorSum = 0; // '+', '-', '*'....
    int operandSum = 0;  // '0 ~ 9'.....
    int flag = 0;
    int a, b;
//input[left]�O�Ʀr�r��
    if(input[left] >= '0' && input[left] <= '9'){ // �r������
        int sum = 0;

        for(i = left; i <= right; i++){
            sum *= 10;
            sum += (input[i] - '0');
        }
        return sum;
    }
    else {           // ���j

        for(i = left; i < right; i++){//0��8
       //�Ʀr
            if(input[i] >= '0' && input[i] <= '9'){//�p�G���O�Ʀr
                if(flag == 0)
                    operandSum++;//�B�⤸(�Ʀr)�[�@

                    flag = 1;
            }
           //�Ů�
            else if(input[i] == ' '){//�p�G���O�Ů�
                flag = 0;
            }
           //�B��l
            else{//�p�G���O�[���άO����
                operatorSum++;//�B��l(�[��)�[�@
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
