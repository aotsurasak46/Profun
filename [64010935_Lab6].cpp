#include<stdio.h>
#include<windows.h>
#include<conio.h>
bool bullet[5];
int bullet_x[5],bullet_y[5];
void setcolor(int fg,int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg*16+fg);
}
void draw_ship(int x, int y)
{
	COORD c = { x , y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE) , c);
	setcolor(2,4);
	printf("<-0->");
}
void erase_ship(int x,int y)
{
	COORD c = { x , y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE) , c);
	setcolor(0,0);
	printf("     ");
	
}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console,&lpCursor);
}
void draw_bullet(int x,int y)
{
	COORD c = { x , y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE) , c);
	printf("*");
}
void erase_bullet(int x,int y)
{
	COORD c = { x , y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE) , c);
	setcolor(0,0);
	printf(" ");
}
void shoot(int i)
{
	erase_bullet(bullet_x[i],bullet_y[i]);
	if(bullet_y[i]>=1)//bullet hit window
	{
		setcolor(4,7);
		draw_bullet(bullet_x[i],--bullet_y[i]);
	}
	else
	{
		bullet[i]=false;
	}
}
int main()
{
	int direct=3;
	setcursor(0);
	setcolor(2,4);
	int x=36,y=20;
	char ch=' ';
	draw_ship(x,y);
	do {
		if (_kbhit())
		{
			ch=_getch();
			//shoot
			if(ch==' ')
			{
				for(int i = 0;i < 5;i++)
				{	
					if(!bullet[i])
					{
						bullet[i]=1;
						bullet_x[i]=x+2;
						bullet_y[i]=y-1;
						break;
					}
				}
			}
			//set direction
			if(ch=='a') {direct=0;}
			if(ch=='d') {direct=1;}
			if(ch=='s')	{direct=3;}
				fflush(stdin);
		}
		
		//move
		if(direct==0&&x>0){erase_ship(x,y);draw_ship(--x,y);}
		if(direct==1&&x<=73){erase_ship(x,y);draw_ship(++x,y);}
		if(direct==3){erase_ship(x,y);draw_ship(x,y);}
		
		//update bullet
		for(int i=0;i<5;i++)
		{
			if(bullet[i]==true)
			{
				shoot(i);
			}
		}
		Sleep(100);
	} while (ch!='x');
	return 0;
}
