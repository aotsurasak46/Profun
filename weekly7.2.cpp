#include <string.h>
#include <stdio.h>
int main()
{
	char string[50][50];
	
	FILE* fp;
	
	fp = fopen("data.txt","w");
	
	int i = 0 ;
	char dot = '.';
	while(string[0][i]!=dot)
	{
		printf("Input data string : \n");
		scanf("%s",&string[i]);
		fprintf(fp,"%s\n",string[i]);
	}
	fclose(fp);
	
	return 0 ;
}	
