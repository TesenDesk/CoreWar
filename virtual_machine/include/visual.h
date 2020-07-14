

#ifndef VISUAL_H
#define VISUAL_H

#include "libft.h"
#include <ncurses.h>
#include "arena.h"
#include "vm.h"

typedef struct  s_wins
{
	WINDOW      *main;
	WINDOW      *chars;
}               t_wins;



typedef struct          s_color_mapcell
{
	int                 player_index;
	int                 cell_index;

}                       t_color_mapcell;



WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);
void    draw_arena(WINDOW *win, t_arena *arena, t_vm *vm);

#endif
