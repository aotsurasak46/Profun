#include<stdio.h>
int main()
{
	int n,digit[3],m;
	int count = 0;
	printf("Enter number between 100 - 999 : ");
	scanf("%d",&n);
	for(int i=0 ;;i++)
	{
		m = n;
		for(int i = 0;n > 0;i++)
		{
			n /= 10;
			count += 1;
		}
		if(count==3)
		{
			for(int j=0;j<3;j++)
			{
				digit[j] = m%10;
				m /= 10;
			}
			m = 1 ;
			for(int j=0;j<3;j++)
			{
				m *= digit[j];
			}
			n = m;
			count = 0;
		}
		else
		{
			printf("0")	;
			break;	
		}
	}
	return 0 ;
}

