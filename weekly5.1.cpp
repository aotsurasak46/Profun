#include <stdio.h>
int main()
{
	int x[10];
	int sum=0;
	float avr;
	for(int i=0;i<10;i++)
	{
		printf("Height of #%d student : ",i+1);
		scanf("%d",&x[i]);
		sum+=x[i];
	}
	avr = sum/10;
	printf("Average height : %.2f",avr);
	return 0;
}

