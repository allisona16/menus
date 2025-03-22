#include <stdio.h>
#include <ncurses.h>
#include <string>
#include "player.h"

using namespace std;
void player();
int main(int argc, char ** argv)
{
	initscr();
	noecho();
	cbreak();
	
	int height, width, starty, startx;
	height = 10; width = 30;
	/*starty = 1; startx = 0;*/
	getmaxyx(stdscr, starty, startx);
	WINDOW *local_win = newwin(height, width, (starty/2)-5, (startx/2)-10);	

	box(local_win, 0 , 0);		/* 0, 0 gives default characters
					 * for the vertical and horizontal lines*/
	refresh();			
	wrefresh(local_win);		 /* show that box */ 

	keypad(local_win, true);
	string choices[3] = {"Snake", "RPG", "Colors"};

	int choice;
	int highlight = 0;

	while(1)
	{
		for(int i = 0; i < 3; i++)
		{
			if(i == highlight)
				wattron(local_win, A_REVERSE);
			mvwprintw(local_win, i+1, 1, "%s",choices[i].c_str());
			wattroff(local_win, A_REVERSE);
			
		}
		choice = wgetch(local_win);

		switch(choice)
		{
			case KEY_UP:
				highlight--;
				if(highlight < 0)
				highlight = 0;
				break;
			case KEY_DOWN:
				highlight++;
				if(highlight > 2)
				highlight = 2;
				break;
			default:
				break;
		}
		if(choice == 10)
			break;

	
	}
	if(choices[highlight] == "RPG")
	{
		player();
	}
	else
	{printw("Your choice was :%s", choices[highlight].c_str());}

	
	getch();
	endwin();
}

void player()
{
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	WINDOW * playwin = newwin(20, 30, (yMax/2)-10, 10);
	box(playwin, 0,0);
	refresh();
	wrefresh(playwin);
	Player * p = new Player(playwin, 1, 1, '@');
	do{
		p->display();
		wrefresh(playwin);
	}while(p->getmv() != 'x');
}