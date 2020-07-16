

#ifndef VISUAL_H
#define VISUAL_H

#include "libft.h"
#include <ncurses.h>
#include "arena.h"
#include "vm.h"

typedef struct  s_wins
{
	WINDOW      *arena;
	WINDOW      *info;
	WINDOW      *help;
}               t_wins;



typedef struct          s_color_mapcell
{
	int                 player_index;
	int                 cell_index;

}                       t_color_mapcell;



t_wins *init_wins(void);
void destroy_win(WINDOW *local_win);
void    draw_arena(t_wins  *wins, t_arena *arena, t_vm *vm);

#endif
