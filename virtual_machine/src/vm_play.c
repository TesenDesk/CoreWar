/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 23:20:21 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/03 23:20:22 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm.h"
#include "visual.h"
#include "arena/prvt_arena.h"



//while (i < 64)
//{
//j = 0;
//wmove(vm->vs->win_arena, i + 2, 5);
//while (j < 64)
//{
//attribute = get_attribute(vm, &vm->vs->map[i * 64 + j], cycles);
//wattron(vm->vs->win_arena, attribute);
//wprintw(vm->vs->win_arena, "%.2x", vm->arena[i * 64 + j]);
//wattroff(vm->vs->win_arena, attribute);
//waddch(vm->vs->win_arena, ' ');
//j++;
//}
//wprintw(vm->vs->win_arena, "\n");
//i++;
//}

void			destroy_dead_carriages(t_list **head, int c_t_d, int cntr)
{
	t_list		*current;
	t_list		*previous;

	current = *head;
	previous = NULL;
	while (current)
	{
		if (carriage_is_alive(current->content, c_t_d, cntr) == FALSE)
		{
			if (previous == NULL)
			{
				*head = current->next;
				ft_lstdelone(&current, carriage_destroy);
				current = *head;
			}
			else
			{
				previous->next = current->next;
				ft_lstdelone(&current, carriage_destroy);
				current = previous->next;
			}
		}
		else
		{
			previous = current;
			current = current->next;
		}
	}
}

int				vm_check(t_vm *self)
{
	destroy_dead_carriages(&(self->carriage_head),
			self->cycles_to_die, self->global_counter);
	if (self->carriage_head == NULL)
		return (FAILURE);
	self->num_checks += 1;
	if (self->num_checks >= MAX_CHECKS || self->num_of_live_ops >= NBR_LIVE)
	{
		self->num_checks = 0;
		self->cycles_to_die -= CYCLE_DELTA;
		if (vm_verbosity_lvl() & 2)
			printf("Cycle to die is now %i\n", self->cycles_to_die);
	}
	self->num_of_live_ops = 0;
	self->cycles_counter = 0;
	return (SUCCESS);
}

void			vm_next_cycle(t_vm *self)
{
	t_list		*list;

	list = self->carriage_head;
	while (list)
	{
//		printf("%p\n", list);
		carriage_take_step(list->content);
		list = list->next;
	}
}

static int ft_sqrt(int k)
{
	int   i;

	i = 2;
	while (i * i < k)
		i += 1;
	return (i);
}


void			vm_play(t_vm *self)
{
	int startx, starty, width, height;
	int ch;
	t_wins      *wins;


	initscr();			/* Start curses mode 		*/
	cbreak();			/* Line buffering disabled, Pass on
					 * everty thing to me 		*/

	height = SQRT_MAP+ 2;
	width = SQRT_MAP * 3 + 2;
	starty = 1;	/* Calculating for a center placement */
	startx = 1;	/* of the window		*/
	wins = init_wins();

	self->wins = wins;
	arena_players_introducing(self->arena);
	self->cycles_to_die = CYCLE_TO_DIE;
	self->cycles_counter = 1;
	self->global_counter = 1;
	while (TRUE)
	{
		if (vm_verbosity_lvl() & 2)
			printf("It is now cycle %i\n", self->global_counter);
		if (self->cycles_to_dump == 0)
		{
			arena_print_dump(self->arena);
			break ;
		}
		vm_next_cycle(self);
		if (self->cycles_to_die <= self->cycles_counter)
		{
			if (vm_check(self) == FAILURE)
			{
				arena_print_winner(self->arena);
				break ;
			}
		}
		self->global_counter += 1;
		self->cycles_counter += 1;
		self->cycles_to_dump -= 1;
		draw_arena(wins, self->arena, self);
//		werase(my_win);
//		wprintw(my_win, "DONE");
//		wrefresh(my_win);
//		getchar();
	}
//	draw_arena(my_win, self->arena, self);
//	werase(my_win);
//	wprintw(my_win, "DONE");
//	wrefresh(my_win);
//	getchar();
}
