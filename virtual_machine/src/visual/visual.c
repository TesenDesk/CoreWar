//
// Created by Mudcrab Stygg on 7/4/20.
//


#include "_visual_private.h"
#include "op.h"
#include "../arena/prvt_arena.h"
#include "../_vm.h"
#include "../carriage/prvt_carriage.h"
#include "../arena/player/prvt_player.h"
#include "op.h"
#include <ncurses.h>





WINDOW *create_newwin(int height, int width, int starty, int startx)
{
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	return local_win;
}

t_wins          *init_wins(void)
{
	t_wins      *wins;
	if (!(wins = ft_memalloc(sizeof(t_wins))))
		exit(-1);
	if (!(wins->arena = create_newwin(SQRT_MAP + 2, SQRT_MAP * 3 + 2, 1, 1)))
		exit(-1);
	if (!(wins->info = create_newwin(10, 75, 1, SQRT_MAP * 3 + 4)))
		exit(-1);
	return (wins);
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


void    init_colors(void)
{
	init_color(COLOR_GRAY, 355, 355, 355);
	init_pair(P_1_HOME, COLOR_RED, COLOR_BLACK);
	init_pair(P_2_HOME, COLOR_YELLOW, COLOR_BLACK);
	init_pair(P_3_HOME, COLOR_GREEN, COLOR_BLACK);
	init_pair(P_4_HOME, COLOR_BLUE, COLOR_BLACK);
	init_pair(P_1_L_HOME, COLOR_BLACK, COLOR_RED);
	init_pair(P_2_L_HOME, COLOR_BLACK, COLOR_YELLOW);
	init_pair(P_3_L_HOME, COLOR_BLACK, COLOR_GREEN);
	init_pair(P_4_L_HOME, COLOR_BLACK, COLOR_BLUE);
	init_pair(P_1_L_OUT, COLOR_WHITE, COLOR_RED);
	init_pair(P_2_L_OUT, COLOR_WHITE, COLOR_YELLOW);
	init_pair(P_3_L_OUT, COLOR_WHITE, COLOR_GREEN);
	init_pair(P_4_L_OUT, COLOR_WHITE, COLOR_BLUE);
	init_pair(NEUTRAL_COL, COLOR_GRAY, COLOR_BLACK);
}

void                init_colormap(t_arena *arena, t_vm *vm, int OFFSET, WINDOW *win)
{
	t_carriage      *carriage_cur;
	t_player        *tmp;
	int             col;
	int             offset;
	int             pos;

	col = P_1_HOME;
	tmp = *(arena->players);
	offset = 0;
	pos = offset;
	while (col <= arena->nb_players)
	{
		while (pos < offset + tmp->code_size)
		{
			arena->colormap[pos % MEM_SIZE].cell_index = col;
			++pos;
		}
		while (pos < offset + OFFSET)
		{
			arena->colormap[pos % MEM_SIZE].cell_index = NEUTRAL_COL;
			++pos;
		}
		offset +=OFFSET;
		++col;
	}
	arena->color_is_set = 1;
}

int     chose_color(t_arena *arena, int index, t_vm *vm, int i)
{
	int ans;
	if (arena->colormap[index % MEM_SIZE].player_index == 0) {
		ans = (COLOR_PAIR(arena->colormap[index % MEM_SIZE].cell_index));

	}
		else if (arena->colormap[index % MEM_SIZE].player_index == arena->colormap[index % MEM_SIZE].cell_index)
		ans =  (COLOR_PAIR(arena->colormap[index % MEM_SIZE].cell_index + HOME_OFFSET));
	else if (arena->colormap[index % MEM_SIZE].cell_index != NEUTRAL_COL)
		ans =  (COLOR_PAIR(arena->colormap[index % MEM_SIZE].cell_index + OUT_OFFSET));
	else
		ans = (COLOR_PAIR(NEUTRAL_COL));
	return (ans);
}




void    rebuild_color_map(t_arena *arena, t_vm *vm, WINDOW *win) {
	t_list *iter;
	t_carriage *carriage_cur;
	int index;

	index = 0;
	iter = vm->carriage_head;
	carriage_cur = NULL;
	if (!(arena->color_is_set)) {
		init_colors();
		init_colormap(arena, vm, (MEM_SIZE / arena->nb_players), win);
	}
	else
		{
		while (iter != NULL) {
			carriage_cur = (t_carriage *) iter->content;
			arena->colormap[carriage_cur->arena_position % MEM_SIZE].player_index = carriage_cur->player_name;
			if (carriage_cur->was_store == TRUE)
			{
				while (index < 4)
				{
					arena->colormap[
						(carriage_cur->stor_pos +
						index) % MEM_SIZE].cell_index = carriage_cur->player_name;
					++index;
				}
				index = 0;
			}
			iter = iter->next;
		}
	}
}

void    print_info(t_vm *vm)
{
	wmove(vm->wins->info, 1, 1);
	wprintw(vm->wins->info, " cycles_to_die:  %d\n", vm->cycles_to_die);
	wmove(vm->wins->info, 2, 1);
	wprintw(vm->wins->info, " cycles_counter: %d\n", vm->cycles_counter);
	wmove(vm->wins->info, 3, 1);
	wprintw(vm->wins->info, " cycles_delta:   %d\n", CYCLE_DELTA);
	wmove(vm->wins->info, 4, 1);
	wprintw(vm->wins->info, " game_speed:     %d\n", vm->speed);
	wmove(vm->wins->info, 5, 1);
	wprintw(vm->wins->info, " TO SPEED_UP PUSH UP_ARROW, TO SPEED_DOWN PUSH DOWN_ARROW(MIN 1 MAX 10)");
//	int c = getch();
//		if (c == KEY_UP)
//		{
//			vm->speed += 1;
//		}
//		else if (c ==  KEY_DOWN) {
//			vm->speed -= 1;
//		}
//	if (vm->speed > 10)
//		vm->speed = 10;
//	if (vm->speed < 1)
//		vm->speed = 1;
//	wmove(vm->wins->info, 6, 1);
//			wprintw(vm->wins->info, "your speed:%d\n", c);
//			getchar();
			box(vm->wins->info, 0, 0);
	wrefresh(vm->wins->info);

}

void    draw_arena(t_wins *wins, t_arena *arena, t_vm *vm)
{
	int sqr;
	int i;
	int j;

	i = 0;
	j = 0;
	vm->wins = wins;
	if(has_colors() == FALSE)
	{	endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}
	start_color();
	werase(wins->arena);
	werase(wins->info);
	rebuild_color_map(arena, vm, wins->info);
	while(i < SQRT_MAP)
	{
		wmove(wins->arena, i + 1, 1);
		while (j < SQRT_MAP) {
			int col = chose_color(arena, (i* 64+j)%MEM_SIZE, vm, i);
			wattron(wins->arena, col);
			wprintw(wins->arena, "%.2x", (unsigned char)arena->data[(i*64 + j++) % MEM_SIZE]);
			wattroff(wins->arena, col);
			waddch(wins->arena, ' ');
		}
		wprintw(wins->arena, "\n");
		j = 0;
		++i;
	}
	box(wins->arena, 0, 0);
	int         ii = 0;
	while (ii < MEM_SIZE)
		arena->colormap[ii++].player_index = 0;
	wrefresh(vm->wins->arena);
	print_info(vm);
	usleep(5000 / vm->speed);
}
