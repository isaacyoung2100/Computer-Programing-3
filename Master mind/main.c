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
		maybeAnswer[i] = 1;//maybeAnswer[0~3124]���g�J1//�t�Ф@�Ӱ}�C�ӰO�����A

	while(1){
		//printf("x");
		for(guess = 0; guess < 3125; guess++){
			if(maybeAnswer[guess] == 1)//�M�䦳�i��O�ѵ����Ĥ@�Ӷ��بӲq
				break;
		}

		printf("I guess...");
		for(i = 0; i < 5; i++)
			printf("%c",colors[guess][i]);//�L�X�Ĥ@�Ӷ���
		printf("\n");

		scanf("%d %d",&black,&white);
		//�M�A�ߤ��ҷQ�����װ����

		for(i = 0; i < 3125; i++){
			if(maybeAnswer[i] == 1){
				b = getBlackPins(colors[guess],colors[i]);//�Ncolors[guess]���°w(colors[0])�P�Ҧ��զX���,�ob
				w = getWhitePins(colors[guess],colors[i]);//�Ncolors[guess]���հw(colors[0])�P�Ҧ��զX���,�ow


				if(b != black || w != white)//�N�Ҧ�b���O0�Bw���O0�����׳��R��
					maybeAnswer[i] = 0;
			}
		}
	}
	//BBYOB
}
