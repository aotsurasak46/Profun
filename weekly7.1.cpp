#include <string.h>
#include <stdio.h>
int main()
{
	int x,y,sum ;	
	FILE* fp1 ;
	FILE* fp2 ;
		
	fp1 = fopen("a.txt","r");
	fp2 = fopen("b.txt","w");
	
	fscanf(fp1,"%d %d",&x,&y);
	
	sum = x + y ;
	
	fprintf(fp2,"%d",sum);
	
	fclose(fp1);
	fclose(fp2);
	
	return 0 ;
}	
