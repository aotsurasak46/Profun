#include <stdio.h>
int n ;
int factorial(int x)
{
	int num[x];
	int multiply = 1 ;
	num[0] = x ;
	for(int i = 0 ;i < x;i ++)
	{
		num[i+1] = num[i] - 1;
	}
	for(int i = 0 ; i < (x - 1) ;i ++)
	{
		multiply *= num[i] ;
	}
	return multiply ;
}
int main()
{
	printf("Input : ");
	scanf("%d",&n);
	printf("Output : %d",factorial(n));
	return 0 ;
}

