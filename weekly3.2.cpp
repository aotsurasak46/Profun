#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("*");
	}
	if(n>1){
		for (int i=1;i<n;i++){
			printf("\n");
			for(int i=0;i<n;i++){
				printf("*");
			}
		}
	}
	else{ 
		}
	return 0;
}

