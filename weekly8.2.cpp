#include <string.h>
#include <stdio.h>

int det(int num[3][3])
{
	int x1,x2,x3,y1,y2,y3;
	int det;
	
	x1 = num[0][0]*num[1][1]*num[2][2];
	x2 = num[0][1]*num[1][2]*num[2][0];
	x3 = num[0][2]*num[1][0]*num[2][1];
	y1 = num[2][0]*num[1][1]*num[0][2];
	y2 = num[2][1]*num[1][2]*num[0][0];
	y3 = num[2][2]*num[1][0]*num[0][1];
	
	det = (x1 + x2 + x3)-(y1 + y2 + y3);
	
	return det;
}
void inverse(int num[3][3])
{
	int deter[9];
	deter[0]=(num[2][1]*num[1][2])-(num[1][1]*num[2][2]); //C11
	deter[1]=(num[1][0]*num[2][2])-(num[2][0]*num[1][2]); //C12
	deter[2]=(num[1][0]*num[2][1])-(num[2][0]*num[1][1]); //C13
	deter[3]=(num[0][1]*num[2][2])-(num[2][1]*num[0][2]); //C21
	deter[4]=(num[0][0]*num[2][2])-(num[2][0]*num[0][2]); //C22
	deter[5]=(num[0][0]*num[2][1])-(num[2][0]*num[0][1]); //C23
	deter[6]=(num[0][1]*num[1][2])-(num[1][1]*num[0][2]); //C31
	deter[7]=(num[0][0]*num[1][2])-(num[1][0]*num[0][2]); //C32
	deter[8]=(num[0][0]*num[1][1])-(num[1][0]*num[0][1]); //C33
	
	printf("%d/%d %d/%d %d/%d\n",deter[0],det(num),deter[3],det(num),deter[6],det(num));
	printf("%d/%d %d/%d %d/%d\n",deter[1],det(num),deter[4],det(num),deter[7],det(num));
	printf("%d/%d %d/%d %d/%d\n",deter[2],det(num),deter[5],det(num),deter[8],det(num));

}
void sum(int num1[3][3],int num2[3][3])
{
	int sum[3][3];

 	for(int i=0;i < 3;i++)
 	{
  		for(int j=0;j < 3;j++)
  		{
  			
   			sum[i][j]=num1[i][j]+num2[i][j];
   			
 		}
 	}
	
	printf("A + B : \n");
	for(int i = 0;i<3;i++)
 	{
  		for(int j = 0;j<3;j++)
  		{
   			printf("%d ",sum[i][j]);
  		}
  		printf("\n");
 	}
}
void diff(int num1[3][3],int num2[3][3])
{
	int diff[3][3];
	
	for(int i=0;i < 3;i++)
 	{
  		for(int j=0;j < 3;j++)
  		{
   			diff[i][j]=num1[i][j]-num2[i][j];
  		}
 	}
	
	printf("A - B : \n");
	for(int i = 0;i<3;i++)
 	{
  		for(int j = 0;j<3;j++)
  		{
   			printf("%d ",diff[i][j]);
  		}
  		printf("\n");
 	}
}

void cross(int num1[3][3],int num2[3][3])
{
	int multi[3][3];

	for(int i = 0 ;i < 3;i++)
 	{
  		for(int j = 0;j < 3;j++)
  		{
   			multi[i][j]=num1[i][0]*num2[0][j]+num1[i][1]*num2[1][j]+num1[i][2]*num2[2][j];
  		}
 	}
	
	printf("A x B : \n");
	for(int i = 0;i<3;i++)
 	{
  		for(int j = 0;j<3;j++)
  		{
   			printf("%d ",multi[i][j]);
  		}
  		printf("\n");
 	}
}

int main()
{
	
	int num1[3][3];
	int num2[3][3];
	
	printf("Input matrix A : \n");
 	for(int i=0;i<3;i++)
 	{
  		scanf("%d %d %d",&num1[i][0],&num1[i][1],&num1[i][2]);
 	}
 
 	printf("Input matrix B : \n");
 	for(int i=0;i<3;i++)
 	{
  		scanf("%d %d %d",&num2[i][0],&num2[i][1],&num2[i][2]);
 	}
	
	
	printf("detA = %d\n",det(num1));
	printf("detB = %d\n",det(num2));
	printf("Inverse A : \n");
	inverse(num1);
	printf("Inverse B : \n");
	inverse(num2);
	sum(num1,num2);
	diff(num1,num2);
	cross(num1,num2);
	
	
	return 0 ;
}	
