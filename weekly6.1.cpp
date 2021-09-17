#include <stdio.h>
int n;
int factorial(int x)
{
	int multiply=1;
	while(x > 0)
	{
		multiply *= x ;
		x -= 1 ;
	}
	return multiply ;
}
int main()
{
	scanf("%d",&n);
	printf("%d",factorial(n));
	return 0;
}

