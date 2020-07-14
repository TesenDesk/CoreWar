

#include "libft.h"
#include <ncurses.h>
#include "arena.h"

typedef struct  s_wins
{
	WINDOW      *main;
	WINDOW      *chars;
}               t_wins;

WINDOW *create_newwin(int height, int width, int starty, int startx);
t_wins              *win_constructor(t_wins win);
void destroy_win(WINDOW *local_win);
void    draw_arena(WINDOW *win, t_arena *arena);
