//
// Created by Mudcrab Stygg on 7/4/20.
//


#include "_visual_private.h"
#include <math.h>
#include "op.h"
#include "../arena/prvt_arena.h"

WINDOW *create_newwin(int height, int width, int starty, int startx)
{
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	return local_win;
}


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


void    draw_arena(WINDOW *win, t_arena *arena)
{
	int sqr;
	int i;
	int j;

	i = 0;
	j = 0;

	if(has_colors() == FALSE)
	{	endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}
	start_color();			/* Start color 			*/
	init_pair(1, COLOR_RED, COLOR_BLACK);

	while(i < SQRT_MAP)
	{
		wmove(win, i+1, 1);
		while (j < SQRT_MAP) {
//			attron(COLOR_PAIR(1));
			wattron(win, 1);
			wprintw(win, "%.2x", (unsigned char)arena->data[i * 64 + j++]);
//			wattroff(win, 1);
//			wprintw(win, "%.2x", are);
			waddch(win, ' ');
			wattroff(win, 1);
		}
		wprintw(win, "\n");
		j = 0;
		++i;
	}
	box(win, 0, 0);
	wrefresh(win);
}
