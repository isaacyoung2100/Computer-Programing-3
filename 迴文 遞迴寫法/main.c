#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 101
/*int palindrome(char text[],int left,int right)
{
    if(left >= right) return 1;
    if(text[left]!=text[right]) return 0;
    return palindrome(text, ++left, --right);
}*/
int palindrome(char arr[], int start, int end)
{
    if(start>=end)  return 1;

    if(arr[start]!=arr[end])
        return 0;
    else
        palindrome(arr, ++start, --end);
}
int main()
{
    char arr[MAX];
    int i,j,k;
    int pc;
    int counter=0;
    char *p;

    srand( time(NULL) );

    for(p=arr ; p<arr+MAX ; p++)
    {
        *p=rand()%26+65;
    }

    for(i=1 ; i<MAX ; i++)
    {
        printf("%c\t", *(arr+i));
        if(i%10==0)
        	printf("\n");

    }

    for(i=1 ; i<MAX ; i++)
    {
    	for(j=1 ; j<MAX ; j++)
    	{
    		if(j>=i)
    		{
    			if(palindrome(arr,i,j))
    			{
    				counter++;
    				for(k=i ; k<=j ; k++)
    				{
    					printf("%c", arr[k]);
					}printf("\n");
				}
			}
		}
	}
	printf("°j¤åÁ`¼Æ: %d", counter);

    return 0;
}
