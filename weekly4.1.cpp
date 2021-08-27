#include<stdio.h>
int main()
{
	int n,x,digit[3];
	printf("Enter number between 100 - 999 : ");
	scanf("%d",&n);
	while(n>=10&&n<=999)
	{
		for(int i=0;i<3;i++)
		{
			digit[i] = n%10 ;
			printf("digit = %d\n",digit[i]);
			if(n>=10)
			{
				n /= 10 ; 
				printf("n = %d\n",n);
			}
			else
			{
				n = 0;
				printf("n = %d\n",n);
			}
		}
		n = 1 ;
		for(int i=0;i<3;i++)
		{
			n *= digit[i];
			printf("n = %d\n",n);
		}
	}
	printf("%d",n);
	return 0 ;
}

