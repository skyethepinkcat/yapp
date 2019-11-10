#include <iostream>
#include "ui.hpp"

ui::ui(){}

void ui::start(){
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	WINDOW* myWin;
	int startx;
	int height = 20;
	int width = 50;
	int starty;
	int ch;
	starty = (LINES - height) / 2;	/* Calculating for a center placement */
	startx = (COLS - width) / 2;	/* of the window		*/
	myWin = create_newwin(height,width,startx,starty);
	while((ch = getch()) != KEY_F(1))
	{	switch(ch)
		{	case KEY_LEFT:
				destroy_win(myWin);
				myWin = create_newwin(height, width, starty,--startx);
				break;
			case KEY_RIGHT:
				destroy_win(myWin);
				myWin = create_newwin(height, width, starty,++startx);
				break;
			case KEY_UP:
				destroy_win(myWin);
				myWin = create_newwin(height, width, --starty,startx);
				break;
			case KEY_DOWN:
				destroy_win(myWin);
				myWin = create_newwin(height, width, ++starty,startx);
				break;
		}
	}




}

WINDOW* ui::create_newwin(int height, int width, int starty, int startx){
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);		/* 0, 0 gives default characters
					 * for the vertical and horizontal
					 * lines			*/
	wrefresh(local_win);		/* Show that box 		*/

	return local_win;
}
void ui::destroy_win(WINDOW *local_win)
{
	/* box(local_win, ' ', ' '); : This won't produce the desired
	 * result of erasing the window. It will leave it's four corners
	 * and so an ugly remnant of window.
	 */
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	/* The parameters taken are
	 * 1. win: the window on which to operate
	 * 2. ls: character to be used for the left side of the window
	 * 3. rs: character to be used for the right side of the window
	 * 4. ts: character to be used for the top side of the window
	 * 5. bs: character to be used for the bottom side of the window
	 * 6. tl: character to be used for the top left corner of the window
	 * 7. tr: character to be used for the top right corner of the window
	 * 8. bl: character to be used for the bottom left corner of the window
	 * 9. br: character to be used for the bottom right corner of the window
	 */
	wrefresh(local_win);
	delwin(local_win);
}

