

#include <ncurses.h>

typedef struct  s_wins
{
	WINDOW      main;
	WINDOW      chars;
}               t_wins;

t_wins              *win_constructor(t_wins win);