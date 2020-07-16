//
// Created by Mudcrab Stygg on 7/4/20.
//


#include "_visual_private.h"
#include <math.h>
#include "op.h"
#include "../arena/prvt_arena.h"
#include "vm.h"
#include "../_vm.h"
#include "../carriage/prvt_carriage.h"
#include "../arena/player/prvt_player.h"
#include "op.h"
#include <ncurses.h>




//static int	get_live_color(t_player *player)
//{
//	int32_t index;
//
//	index = ((player->id - 1) % MAX_PLAYER_ID) + 1;
//	if (index == MIN_PLAYER_ID)
//		return (COLOR_PAIR(LIVE_GREEN) | A_BOLD);
//	else if (index == MIN_PLAYER_ID + 1)
//		return (COLOR_PAIR(LIVE_YELLOW) | A_BOLD);
//	else if (index == MIN_PLAYER_ID + 2)
//		return (COLOR_PAIR(LIVE_RED) | A_BOLD);
//	else
//		return (COLOR_PAIR(LIVE_CYAN) | A_BOLD);
//}
//
//int			get_attribute(t_vm *vm, t_attr *attribute, ssize_t cycles)
//{
//	if (cycles != vm->cycles
//	    && vm->cycles_to_die > 0
//	    && attribute->wait_cycles_live > 0)
//		attribute->wait_cycles_live--;
//	if (cycles != vm->cycles
//	    && vm->cycles_to_die > 0
//	    && attribute->wait_cycles_store > 0)
//		attribute->wait_cycles_store--;
//	if (attribute->wait_cycles_live)
//		return (get_live_color(attribute->player_live));
//	else if (attribute->wait_cycles_store)
//		return (g_colors_players[attribute->index] | A_BOLD);
//	else
//		return (g_colors_players[attribute->index]);
//}

///*
//** Color
//*/
//


//
///*
//** Color pairs
//*/
//
//# define GRAY					9
//# define GREEN					10


//# define YELLOW					11
//# define RED					12
//# define CYAN					13
//# define GRAY_CURSOR			14make
//# define GREEN_CURSOR			15
//# define YELLOW_CURSOR			16
//# define RED_CURSOR				17
//# define CYAN_CURSOR			18
//# define LIVE_GREEN				19
//# define LIVE_YELLOW			20
//# define LIVE_RED				21
//# define LIVE_CYAN				22
//
///*
//** Buttons
//*/

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
	if (!(wins->info = create_newwin(15, 40, 1, SQRT_MAP * 3 + 4)))
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
			wprintw(win, "%d, %d", pos, OFFSET);
			wrefresh(win);
			werase(win);
			arena->colormap[pos].cell_index = col;
			++pos;
		}
		while (pos < offset + OFFSET)
		{
			arena->colormap[pos].cell_index = NEUTRAL_COL;
			++pos;
		}
		offset +=OFFSET;
		++col;
	}
	arena->color_is_set = 1;
}

int     chose_color(t_arena *arena, int index)
{
//	printf("c_i:%d\n", arena->colormap[index].cell_index);
/*
 * probably here sega
 */
	if (arena->colormap[index].player_index == 0) {
		return (COLOR_PAIR(arena->colormap[index].cell_index));

	}
	else if (arena->colormap[index].player_index == arena->colormap[index].cell_index)
	{
		return (COLOR_PAIR(arena->colormap[index].cell_index + HOME_OFFSET));
	}
	else if (arena->colormap[index].cell_index != NEUTRAL_COL)
		return (COLOR_PAIR(arena->colormap[index].cell_index + OUT_OFFSET));
	else
		return (COLOR_PAIR(NEUTRAL_COL));
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
			arena->colormap[carriage_cur->arena_position].player_index = carriage_cur->player_name;
			if (carriage_cur->was_store == TRUE) {
				while (index < 4) {
					arena->colormap[
						(((t_carriage *) (iter->content))->stor_pos) +
						index].cell_index = carriage_cur->player_name;
					++index;
				}
				index = 0;
			}
			iter = iter->next;
		}
	}
}

void    draw_arena(t_wins *wins, t_arena *arena, t_vm *vm)
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
	werase(wins->arena);
	werase(wins->info);


	if(vm->cycles_counter > 1244)
	{
		werase(wins->info);
		wprintw(wins->info,"BEFORE REBUILD\n");
		wrefresh(wins->info);
		getchar();}
	rebuild_color_map(arena, vm, wins->info);
	if (vm->cycles_counter > 1244)
	{
		werase(wins->info);
		wprintw(wins->info,"AFTER REBUILD\n");
		wrefresh(wins->info);
		getchar();}
	while(i < SQRT_MAP)
	{
		wmove(wins->arena, i+1, 1);
		while (j < SQRT_MAP) {
			int col = chose_color(arena, i* 64+j);
			wattron(wins->arena, col);
			wprintw(wins->arena, "%.2x", (unsigned char)arena->data[i * 64 + j++]);
			wattroff(wins->arena, col);
			waddch(wins->arena, ' ');
		}
		if (vm->cycles_counter > 1244)
		{
			werase(wins->info);
			wprintw(wins->info,"AFTER J, %d, %d\n", j, i);
			wrefresh(wins->info);
			getchar();}
		wprintw(wins->arena, "\n");
		j = 0;
		++i;
	}
	box(wins->arena, 0, 0);
	t_list  *tmptmp = vm->carriage_head;
	t_carriage  *aaa = (t_carriage *)(tmptmp->content);
	if (vm->cycles_counter > 1244) {

		wprintw(wins->info,"!±!!!!!!!!!!!!!!\n");
		wrefresh(wins->info);
		getchar();
	}
	while(tmptmp)
	{
		aaa->was_store =0;
		aaa->stor_pos = 0;
		aaa->was_live = 0;
		tmptmp = tmptmp->next;
	}
	box(wins->info, 0, 0);
	wprintw(wins->info, "cycles_to_die: %d\n", vm->cycles_to_die);
	wprintw(wins->info, "cycles_counter: %d\n", vm->cycles_counter);

	wrefresh(wins->arena);
	wrefresh(wins->info);
	if (vm->cycles_counter > 1244)
	{
		wprintw(wins->info,"AAAAAAAAAAAAAAAA\n");
		wrefresh(wins->info);
		getchar();}
	usleep(5000);
//	getchar();
}
