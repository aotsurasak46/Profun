#include <stdio.h>
float average(int n)
{
	int x[n];
	int sum=0;
	float avr;
	for(int i=0;i<n;i++)
	{
		printf("Height of #%d student : ",i+1);
		scanf("%d",&x[i]);
		sum+=x[i];
	}
	avr = sum/n;
	return avr;
}
int main()
{
	printf("Average height : %.2f",average(10));
	return 0;
}

