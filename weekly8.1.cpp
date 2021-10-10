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
	
	sum[0][0]=num1[0][0]+num2[0][0];
	sum[0][1]=num1[0][1]+num2[0][1];
	sum[0][2]=num1[0][2]+num2[0][2];
	sum[1][0]=num1[1][0]+num2[1][0];
	sum[1][1]=num1[1][1]+num2[1][1];
	sum[1][2]=num1[1][2]+num2[1][2];
	sum[2][0]=num1[2][0]+num2[2][0];
	sum[2][1]=num1[2][1]+num2[2][1];
	sum[2][2]=num1[2][2]+num2[2][2];
	
	printf("A + B : \n");
	printf("%d %d %d\n",sum[0][0],sum[0][1],sum[0][2]);
	printf("%d %d %d\n",sum[1][0],sum[1][1],sum[1][2]);
	printf("%d %d %d\n",sum[2][0],sum[2][1],sum[2][2]);
}
void diff(int num1[3][3],int num2[3][3])
{
	int diff[3][3];
	
	diff[0][0]=num1[0][0]-num2[0][0];
	diff[0][1]=num1[0][1]-num2[0][1];
	diff[0][2]=num1[0][2]-num2[0][2];
	diff[1][0]=num1[1][0]-num2[1][0];
	diff[1][1]=num1[1][1]-num2[1][1];
	diff[1][2]=num1[1][2]-num2[1][2];
	diff[2][0]=num1[2][0]-num2[2][0];
	diff[2][1]=num1[2][1]-num2[2][1];
	diff[2][2]=num1[2][2]-num2[2][2];
	
	printf("A - B : \n");
	printf("%d %d %d\n",diff[0][0],diff[0][1],diff[0][2]);
	printf("%d %d %d\n",diff[1][0],diff[1][1],diff[1][2]);
	printf("%d %d %d\n",diff[2][0],diff[2][1],diff[2][2]);
}
void cross(int num1[3][3],int num2[3][3])
{
	int multi[3][3];
	

	multi[0][0]=num1[0][0]*num2[0][0]+num1[0][1]*num2[1][0]+num1[0][2]*num2[2][0];//11
	multi[0][1]=num1[0][0]*num2[0][1]+num1[0][1]*num2[1][1]+num1[0][2]*num2[2][1];//12
	multi[0][2]=num1[0][0]*num2[0][2]+num1[0][1]*num2[1][2]+num1[0][2]*num2[2][2];//13
	multi[1][0]=num1[1][0]*num2[0][0]+num1[1][1]*num2[1][0]+num1[1][2]*num2[2][0];//21
	multi[1][1]=num1[1][0]*num2[0][1]+num1[1][1]*num2[1][1]+num1[1][2]*num2[2][1];//22
	multi[1][2]=num1[1][0]*num2[0][2]+num1[1][1]*num2[1][2]+num1[1][2]*num2[2][2];//23
	multi[2][0]=num1[2][0]*num2[0][0]+num1[2][1]*num2[1][0]+num1[2][2]*num2[2][0];//31
	multi[2][1]=num1[2][0]*num2[0][1]+num1[2][1]*num2[1][1]+num1[2][2]*num2[2][1];//32
	multi[2][2]=num1[2][0]*num2[0][2]+num1[2][1]*num2[1][2]+num1[2][2]*num2[2][2];//33
	
	
	printf("A x B : \n");
	printf("%d %d %d\n",multi[0][0],multi[0][1],multi[0][2]);
	printf("%d %d %d\n",multi[1][0],multi[1][1],multi[1][2]);
	printf("%d %d %d\n",multi[2][0],multi[2][1],multi[2][2]);
	
}
int main()
{
	
	int num1[3][3];
	int num2[3][3];
	
	printf("Input matrix A :\n");
	scanf("%d %d %d",&num1[0][0],&num1[0][1],&num1[0][2]);
	scanf("%d %d %d",&num1[1][0],&num1[1][1],&num1[1][2]);
	scanf("%d %d %d",&num1[2][0],&num1[2][1],&num1[2][2]);
	
	printf("Input matrix B :\n");
	scanf("%d %d %d",&num2[0][0],&num2[0][1],&num2[0][2]);
	scanf("%d %d %d",&num2[1][0],&num2[1][1],&num2[1][2]);
	scanf("%d %d %d",&num2[2][0],&num2[2][1],&num2[2][2]);
	
	
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
