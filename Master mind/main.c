#include <stdio.h>
#include <time.h>
#define size 100

char colors[3125][5], avail[5] = {'R','G','B','Y','O'};
int maybeAnswer[3125];

int getWhitePins(char A[],char B[]){
	int i,j,sum = 0;

	char a[5], b[5];

	for(i = 0; i < 5; i++){
		if(A[i] == B[i]){
			a[i] = b[i] = 'X';
		}
		else {
			a[i] = A[i];
			b[i] = B[i];
		}
	}

	for(i = 0; i < 5; i++){
		for(j = 0; j < 5; j++){
			if(a[i] == b[j] && a[i] != 'X'){
				a[i] = b[j] = 'X';
				sum++;
			}
		}
	}

	return sum;
}

int getBlackPins(char A[],char B[]){
	int i, sum = 0;

	for(i = 0; i < 5; i++){
		if(A[i] == B[i])
			sum++;
	}

	return sum;
}

int main()
{
	int i,j,k,m,n,index=0,guess,black,white,b,w;
	for(i = 0; i < 5; i++)
	for(j = 0; j < 5; j++)
	for(k = 0; k < 5; k++)
	for(m = 0; m < 5; m++)
	for(n = 0; n < 5; n++){
		colors[index][0] = avail[i];
		colors[index][1] = avail[j];
		colors[index][2] = avail[k];
		colors[index][3] = avail[m];
		colors[index][4] = avail[n];
		index++;
	}

	for(i = 0; i < 3125; i++)
		maybeAnswer[i] = 1;//maybeAnswer[0~3124]都寫入1//另創一個陣列來記錄狀態

	while(1){
		//printf("x");
		for(guess = 0; guess < 3125; guess++){
			if(maybeAnswer[guess] == 1)//尋找有可能是解答的第一個項目來猜
				break;
		}

		printf("I guess...");
		for(i = 0; i < 5; i++)
			printf("%c",colors[guess][i]);//印出第一個項目
		printf("\n");

		scanf("%d %d",&black,&white);
		//和你心中所想的答案做比對

		for(i = 0; i < 3125; i++){
			if(maybeAnswer[i] == 1){
				b = getBlackPins(colors[guess],colors[i]);//將colors[guess]的黑針(colors[0])與所有組合比對,得b
				w = getWhitePins(colors[guess],colors[i]);//將colors[guess]的白針(colors[0])與所有組合比對,得w


				if(b != black || w != white)//將所有b不是0且w不是0的答案都刪掉
					maybeAnswer[i] = 0;
			}
		}
	}
	//BBYOB
}
