#include<stdio.h>
int main(){
	int num[1];
	for(int i=0;i<2;i++){
		printf("Enter number %d : ",i+1);
		scanf("%d",&num[i]);
	}
	printf("%d + %d = %d",num[0],num[1],num[0]+num[1]);
	printf("%d - %d = %d",num[0],num[1],num[0]-num[1]);
	printf("%d * %d = %d",num[0],num[1],num[0]*num[1]);
	printf("%d / %d = %d",num[0],num[1],num[0]/num[1]);
	return 0;
}

