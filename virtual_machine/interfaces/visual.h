

#ifndef VISUAL_H
#define VISUAL_H

#include "libft.h"
#include <ncurses.h>
#include "arena.h"
#include "vm.h"

typedef struct s_wins			t_wins;
typedef struct s_color_mapcell	t_color_mapcell;

typedef struct  s_wins
{
	WINDOW      *arena;
	WINDOW      *info;
	WINDOW      *champ;
	WINDOW      *win;
//	WINDOW      *help;
}               t_wins;

typedef struct          s_color_mapcell
{
	int                 player_index;
	int                 cell_index;
	int                 store_index;

}                       t_color_mapcell;



t_wins  *init_wins(void);
void    destroy_win(WINDOW *local_win);
void    draw_arena(t_vm *vm);
void    init_curses(void);
void    erase_windows(t_vm *vm);
void    print_windows(t_vm *vm);
void    process_keys(t_vm *self);
void    print_winner_visual(t_vm *vm);

#endif
