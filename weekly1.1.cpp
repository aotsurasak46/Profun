#include<stdio.h>
int main(){
	int x,y,z,i;
	printf("Enter number 1 : ");
	scanf("%d",&x);
	printf("Enter number 2 : ");
	scanf("%d",&y);
	printf("Enter number 3 : ");
	scanf("%d",&z);
	if(x<y&&x<z){
		printf("The minimum number is : %d",x);
	}
	else if(y<z&&y<x){
		printf("The minimum number is : %d",y);
	}
	else if(z<x&&z<y){
		printf("The minimum number is : %d",z);
	}
}

