#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player {
 public:
	Player(WINDOW * win, int y, int x, char c);
	void mvUp();
	void mvDown();
	void mvLeft();
	void mvRight();
	int getmv();
	void display();

 private:
	int xLoc, yLoc, xMax, yMax;
	char character;
	WINDOW * curwin;
};

Player::Player(WINDOW * win, int y, int x, char c)
{
	curwin = win;
	yLoc = y;
	xLoc = x;
	character = c;
	getmaxyx(curwin, yMax, xMax);
	keypad(curwin, true);

}

void Player::mvUp()
{
	mvwaddch(curwin, yLoc, xLoc, ' ');
	yLoc--;
	if(yLoc < 1)
		yLoc = 1;
}
void Player::mvDown()
{
	mvwaddch(curwin, yLoc, xLoc, ' ');
	yLoc++;
	if(yLoc > yMax-2)
		yLoc = yMax-2;
}

void Player::mvLeft()
{
	mvwaddch(curwin, yLoc, xLoc, ' ');
	xLoc--;
	if(xLoc < 1)
		xLoc = 1;

}
void Player::mvRight()
{
	mvwaddch(curwin, yLoc, xLoc, ' ');
	xLoc++;
	if(xLoc > xMax-2)
		xLoc = xMax-2;
}

int Player::getmv()
{
	int choice = wgetch(curwin);
	switch(choice)
	{
		case KEY_UP:
			mvUp();
			break;
		case KEY_DOWN:
			mvDown();
			break;
		case KEY_LEFT:
			mvLeft();
			break;
		case KEY_RIGHT:
			mvRight();
			break;
		default:
			break;
	}
	return choice;
}
void Player::display()
{
	mvwaddch(curwin, yLoc, xLoc, character);

}

#endif 