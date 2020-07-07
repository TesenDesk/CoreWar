//
// Created by Mudcrab Stygg on 7/4/20.
//


#include "_visual_private.h"

WINDOW *create_newwin(int height, int width, int starty, int startx)
{
	WINDOW *local_win;
	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);
	wrefresh(local_win);
	return local_win;
}


//t_wins            *win_constructor(t_wins win)
//{
//	t_wins        *new;
//	if (!(new = (t_wins*)malloc(sizeof(t_wins))))
//		exit(-1);
//	if (!(new->main = create_newwin(0,0,0,0)))
//		exit(-1);
//	if (!(new->chars = create_newwin(0,0,0,0)))
//		exit(-1);
//	if (!(new->main = create_newwin(0,0,0,0)))
//		exit(-1);
//}


void destroy_win(WINDOW *local_win)
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
