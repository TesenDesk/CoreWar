//
// Created by Mudcrab Stygg on 7/14/20.
//

#ifndef COREWAR_VISUAL_H
#define COREWAR_VISUAL_H
#include <ncurses.h>
#include "arena.h"
#include "vm.h"




typedef struct          s_color_mapcell t_color_mapcell;


WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);
void    draw_arena(WINDOW *win, t_arena *arena, t_vm *vm);
#endif //COREWAR_VISUAL_H
