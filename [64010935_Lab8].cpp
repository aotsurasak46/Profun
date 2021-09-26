#include <windows.h>
#include <time.h>
#include <stdio.h>
#define scount 80
#define screen_x 80
#define screen_y 25

HANDLE rHnd;
HANDLE wHnd;
DWORD fdwMode;
CHAR_INFO consoleBuffer[ screen_x * screen_y ];
COORD bufferSize = { screen_x , screen_y };
COORD characterPos = { 0 , 0 };
SMALL_RECT windowSize = { 0 , 0 , screen_x-1, screen_y-1 };
COORD star[scount];
int life = 10 ;
bool play = true ;

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE) , c);
}
char cursor(int x, int y)
{
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	char buf[2]; COORD c = {x,y}; DWORD num_read;
	if(!ReadConsoleOutputCharacter(hStd,(LPTSTR)buf,1,c,(LPDWORD)&num_read) )
		return '\0';
	else
		return buf[0];
}

int setMode()
{
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	SetConsoleMode(rHnd, fdwMode);
	return 0;
}
int setConsole(int x, int y)
{
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	return 0;
}

void clear_buffer()
{
	for (int y = 0; y < screen_y; ++y) {
		for (int x = 0; x < screen_x; ++x) {
			consoleBuffer[x + screen_x * y].Char.AsciiChar = 0;
			consoleBuffer[x + screen_x * y].Attributes = 7;
		}
	}
}
void fill_buffer_to_console()
{
	WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos,&windowSize);
}
void init_star()
{
	int x , y ;
	srand(time(NULL));
	for(int i;i < scount ;i++)
	{
		x = rand()%80;
		y = rand()%25;
		star[i].X = x;
		star[i].Y = y;
	}
}
void star_fall()
{
	int i;
	for (i = 0; i < scount; i++) {
		if (star[i].Y >= screen_y-1) 
		{
			star[i].X = rand() % screen_x ;
			star[i].Y = 1 ;
		}
		else 
		{
			star[i].X = star[i].X ;
			star[i].Y = star[i].Y + 1 ;
			if(cursor(star[i].X, star[i].Y+1)=='<'||cursor(star[i].X, star[i].Y+1)=='-'||cursor(star[i].X, star[i].Y+1)=='0'||cursor(star[i].X, star[i].Y+1)=='-'||cursor(star[i].X, star[i].Y+1)=='>')
			{
				life -= 1 ;
				while(star[i].Y<25)
				{
					gotoxy(star[i].X,star[i].Y+1);
					printf(" ");
					star[i].Y++;
				}
				if(life==0)
				{
					play = false ;
				}
			}
		}
	}
}
void fill_star_to_buffer()
{
	for (int x = 0; x < 80; x++) 
	{
		consoleBuffer[star[x].X + screen_x * star[x].Y].Char.AsciiChar = '*';
		consoleBuffer[star[x].X + screen_x * star[x].Y].Attributes = 7;
	}
}


void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console,&lpCursor);
}

void setcolor(int fg,int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg*16+fg);
}
int main()
{
	
	setcursor(0);
	DWORD numEvents = 0;
	DWORD numEventsRead = 0;	
	init_star();
	srand(time(NULL));
	setConsole(screen_x, screen_y);
	setMode();
	
	int i = 0;
	while (play)
	{
		star_fall();
		clear_buffer();
		fill_star_to_buffer();
		fill_buffer_to_console();
		GetNumberOfConsoleInputEvents(rHnd, &numEvents);
		if (numEvents != 0) 
		{
			INPUT_RECORD* eventBuffer = new INPUT_RECORD[numEvents];
			ReadConsoleInput(rHnd, eventBuffer, numEvents, &numEventsRead);
			for (DWORD i = 0; i < numEventsRead; ++i) 
			{
				if (eventBuffer[i].EventType == KEY_EVENT && eventBuffer[i].Event.KeyEvent.bKeyDown == true ) 
				{
					if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE) 
					{
						play = false;
					}
					
				}
				else if (eventBuffer[i].EventType == MOUSE_EVENT)
				{
					int posx = eventBuffer[i].Event.MouseEvent.dwMousePosition.X;
					int posy = eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;
					if (eventBuffer[i].Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)
					{
						setcolor(rand()%16,0);
						gotoxy(posx,posy);
						printf("<-0->");
					}
					else if (eventBuffer[i].Event.MouseEvent.dwEventFlags & MOUSE_MOVED )
					{
						gotoxy(posx,posy);
						printf("<-0->");
						if(posx >= 75){posx = 75;gotoxy(posx,posy);printf("<-0->");}
					}
				}
			}
			delete[] eventBuffer;
		}
		
		
		Sleep(100);
	}
	return 0;
}
