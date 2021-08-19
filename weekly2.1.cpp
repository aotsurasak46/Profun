#include<stdio.h>
int main(){
	int x,y,i;
	scanf("%d",&x);
	scanf("%d",&y);
	for(i=0;i<4;i++){
		switch (i) 
		{
			case 0:
			printf("%d\n",x+y);
			break;
			case 1:
			printf("%d\n",x-y);
			break;
			case 2:
			printf("%d\n",x*y);
			break;
			case 3:
			printf("%d",x/y);
			break;
		}
	}
	return 0;
}

