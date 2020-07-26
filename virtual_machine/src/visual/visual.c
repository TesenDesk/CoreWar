//
// Created by Mudcrab Stygg on 7/4/20.
//


#include "prvt_visual.h"
#include "op.h"
#include "../arena/prvt_arena.h"
#include "../_vm.h"
#include "../carriage/prvt_carriage.h"
#include "../arena/player/prvt_player.h"
#include "../vm_params/prvt_vm_params.h"
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
	if (!(wins->info = create_newwin(9, 75, 1, SQRT_MAP * 3 + 4)))
		exit(-1);
	if (!(wins->champ = create_newwin(14, 53, 10, SQRT_MAP * 3 + 4)))
		exit(-1);
	if (!(wins->win = create_newwin(4, 38, SQRT_MAP + 3, 1)))
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
	init_pair(P_1_L_WIN, COLOR_CYAN, COLOR_RED);
	init_pair(P_2_L_WIN, COLOR_CYAN, COLOR_YELLOW);
	init_pair(P_3_L_WIN, COLOR_CYAN, COLOR_GREEN);
	init_pair(P_4_L_WIN, COLOR_CYAN, COLOR_BLUE);
	init_pair(B_INFO, COLOR_CYAN, COLOR_BLACK);
	init_pair(NEUTRAL_COL, COLOR_GRAY, COLOR_BLACK);
}

void                init_colormap(t_arena *arena, t_vm *vm, int OFFSET)
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
			arena->colormap[pos++ % MEM_SIZE].cell_index = col;
		while (pos < offset + OFFSET)
			arena->colormap[pos++ % MEM_SIZE].cell_index = NEUTRAL_COL;
		offset +=OFFSET;
		++col;
	}
	arena->color_is_set = 1;
}

int     chose_color(t_arena *arena, int index, t_vm *vm, int i)
{
	int ans;
	if (arena->colormap[index % MEM_SIZE].player_index == 0)
		ans = (COLOR_PAIR(arena->colormap[index % MEM_SIZE].cell_index));
	else if (arena->colormap[index % MEM_SIZE].player_index == arena->colormap[index % MEM_SIZE].cell_index)
		ans =  (COLOR_PAIR(arena->colormap[index % MEM_SIZE].cell_index + HOME_OFFSET));
	else if (arena->colormap[index % MEM_SIZE].cell_index != NEUTRAL_COL)
		ans =  (COLOR_PAIR(arena->colormap[index % MEM_SIZE].cell_index + OUT_OFFSET));
	else
		ans = (COLOR_PAIR(NEUTRAL_COL));
	if (arena->colormap[index % MEM_SIZE].store_index == 1)
		ans |= WA_BOLD;
	return (ans);
}

void    rebuild_color_map(t_arena *arena, t_vm *vm)
{
	t_list *iter;
	int index;

	index = 0;
	iter = vm->carriage_head;
	while (iter != NULL)
	{
		arena->colormap[((t_carriage*)iter->content)->arena_position % MEM_SIZE].player_index
		= ((t_carriage*)iter->content)->player_name;
		arena->carriage_num[((t_carriage *) iter->content)->player_name - 1] += 1;
		if (((t_carriage *) iter->content)->was_store == TRUE)
		{
			while (index < 4)
			{
				arena->colormap[
					(((t_carriage *) iter->content)->stor_pos +
					index) % MEM_SIZE].cell_index = ((t_carriage *) iter->content)->player_name;
				arena->colormap[
					(((t_carriage *) iter->content)->stor_pos +
					 index) % MEM_SIZE].store_index = 1;
				++index;
			}
			index = 0;
		}
		iter = iter->next;
	}
}

void    draw_basic_info(t_vm *vm)
{
	wattron(vm->wins->info, COLOR_PAIR(B_INFO) | A_BOLD);
	wmove(vm->wins->info, 1, 1);
	wprintw(vm->wins->info, " CYCLES_TO_DIE:   %zu\n", (unsigned  int)vm->cycles_to_die);
	wmove(vm->wins->info, 2, 1);
	wprintw(vm->wins->info, " CURRENT_COUNTER: %zu\n", (unsigned int)vm->cycles_counter);
	wmove(vm->wins->info, 3, 1);
	wprintw(vm->wins->info, " GLOBAL_COUNTER:  %d\n", vm->global_counter);
	wmove(vm->wins->info, 4, 1);
	wprintw(vm->wins->info, " CYCLES_DELTA:    %d\n", CYCLE_DELTA);
	wmove(vm->wins->info, 5, 1);
	wprintw(vm->wins->info, " GAME_SPEED:      %d\n", vm->speed);
	wmove(vm->wins->info, 6, 1);
	wprintw(vm->wins->info, " TO SPEED_UP PUSH UP_ARROW, TO SPEED_DOWN PUSH DOWN_ARROW(MIN 1 MAX 10)");
	wmove(vm->wins->info, 7, 1);
	wprintw(vm->wins->info, "                 PRESS 'x' TO GO TO JUMP TO THE END");
	wattroff(vm->wins->info, COLOR_PAIR(B_INFO) | A_BOLD);
}

void    draw_champ_info(t_vm *vm)
{
	int i;

	i = 0;
	while (i < (unsigned int) vm->arena->nb_players)
	{
		wattron(vm->wins->champ, COLOR_PAIR(P_1_HOME + i) | A_BOLD);
		wmove(vm->wins->champ, i *3  + 1, 1);
		wprintw(vm->wins->champ, "P_%d_name: %40s", i+1, vm->arena->players[i]->text_name);
		wmove(vm->wins->champ, i*3  + 2, 1);
		wprintw(vm->wins->champ, "P_%d_comment: %37s", i + 1, vm->arena->players[i]->text_comment);
		wmove(vm->wins->champ, i*3  + 3, 1);
		wprintw(vm->wins->champ, "carriage_num: %36d", vm->arena->carriage_num[i]);
		wattroff(vm->wins->champ, COLOR_PAIR(P_1_HOME +i ) | A_BOLD);
		++i;
	}
}

void    draw_arena(t_vm *vm)
{
	int sqr;
	int i;
	int j;

	i = 0;
	j = 0;
	rebuild_color_map(vm->arena, vm);
	while(i < SQRT_MAP)
	{
		wmove(vm->wins->arena, i + 1, 1);
		while (j < SQRT_MAP) {
			int col = chose_color(vm->arena, (i* 64 + j)%MEM_SIZE, vm, i);
			wattron(vm->wins->arena, col);
			wprintw(vm->wins->arena, "%.2x", (unsigned char)vm->arena->data[(i*64 + j++) % MEM_SIZE]);
			wattroff(vm->wins->arena, col);
			waddch(vm->wins->arena, ' ');
		}
		wprintw(vm->wins->arena, "\n");
		j = 0;
		++i;
	}
}

void    erase_windows(t_vm *vm)
{
	int i;

	i = 0;
	werase(vm->wins->arena);
	werase(vm->wins->info);
	werase(vm->wins->champ);
	while(i < MEM_SIZE)
	{
		vm->arena->colormap[i].player_index = 0;
		vm->arena->colormap[i].store_index = 0;

		++i;
	}
	i = 0;
	while (i < 4)
		vm->arena->carriage_num[i++] = 0;
}


void    print_windows(t_vm *vm)
{
	if (!(vm->arena->color_is_set)) {
		init_colors();
		init_colormap(vm->arena, vm, (MEM_SIZE / vm->arena->nb_players));
	}
		draw_arena(vm);
		draw_basic_info(vm);
		draw_champ_info(vm);
		box(vm->wins->arena, 0, 0);
		box(vm->wins->info, 0, 0);
		box(vm->wins->champ, 0, 0);
		wrefresh(vm->wins->champ);
		wrefresh(vm->wins->arena);
		wrefresh(vm->wins->info);
}

void    init_curses(void)
{
	initscr();			/* Start curses mode 		*/
	cbreak();			/* Line buffering disabled, Pass on
					 * everty thing to me 		*/
	if(has_colors() == FALSE)
	{	endwin();
		ft_printf("Your terminal does not support color\n");
		exit(1);
	}
	start_color();
}

void process_keys(t_vm *self)
{
	int c;

	c = getch();
	self->key = c;
	if (c == 65)
	{
		wattron(self->wins->info, COLOR_PAIR(B_INFO) | A_BOLD);
		self->speed += 1;
		if (self->speed > 10)
			self->speed = 10;
		wattroff(self->wins->info, COLOR_PAIR(B_INFO) | A_BOLD);

	}
	else if (c == 66)
	{

		wattron(self->wins->info, COLOR_PAIR(B_INFO) | A_BOLD);
		self->speed -= 1;
		if (self->speed < 1)
			self->speed = 1;
		wattroff(self->wins->info, COLOR_PAIR(B_INFO) | A_BOLD);
	}
	else if (c == 120)
	{
		self->urgent_break = TRUE;
	}
	getch();
}

void    print_winner_visual(t_vm *vm)
{
	werase(vm->wins->win);
	wattron(vm->wins->win, COLOR_PAIR(P_1_HOME + vm->arena->players[vm->arena->last_live_player - 1]->name - 1) | A_BOLD);
	wmove(vm->wins->win, 1, 1);
	wprintw(vm->wins->win,"%-20s(PLAYER #%d) WON!\n", vm->arena->players[vm->arena->last_live_player - 1]->text_name,
	       vm->arena->players[vm->arena->last_live_player - 1]->name);
	wattroff(vm->wins->win, COLOR_PAIR(P_1_HOME + vm->arena->players[vm->arena->last_live_player - 1]->name - 1) | A_BOLD);
	wattron(vm->wins->win, COLOR_PAIR(B_INFO));
	wmove(vm->wins->win, 2, 1);
	wprintw(vm->wins->win, "       PRESS_ANY_KEY_TO_EXIT\n");
	wattroff(vm->wins->win, COLOR_PAIR(B_INFO) | A_BOLD);
	box(vm->wins->win, 0, 0);
	wrefresh(vm->wins->win);
	nodelay(stdscr, FALSE);
}
