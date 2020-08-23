/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 23:20:21 by yurezz            #+#    #+#             */
/*   Updated: 2020/08/09 14:59:14 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_vm.h"
#include "visual.h"
#include "prvt_arena.h"
#include "ncurses.h"
#include "prvt_carriage.h"
// #include "visual.h"

#include "prvt_visual.h"



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
			ft_printf("Cycle to die is now %i\n", self->cycles_to_die);
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
		carriage_take_step(list->content);
		list = list->next;
	}
}


void			vm_play(t_vm *self)
{
	arena_players_introducing(self->arena);
	self->cycles_to_die = CYCLE_TO_DIE;
	self->cycles_counter = 1;
	self->global_counter = 1;
	while (TRUE)
	{
		if (self->cycles_to_dump == 0)
		{
			arena_print_dump(self->arena);
			break ;
		}
		if (vm_verbosity_lvl() & 2)
			ft_printf("It is now cycle %i\n", self->global_counter);
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
	}
}


void			vm_play_visual(t_vm *self)
{
	init_curses();
	self->wins = init_wins();
	arena_players_introducing(self->arena);
	self->cycles_to_die = CYCLE_TO_DIE;
	self->cycles_counter = 1;
	self->global_counter = 1;
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	while (TRUE)
	{
		if (self->urgent_break == FALSE) {
			process_keys(self);
			erase_windows(self);
		}
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
				print_winner_visual(self);
				getch();
				exit(-1);
			}
		}
		self->global_counter += 1;
		self->cycles_counter += 1;
		self->cycles_to_dump -= 1;
		if (self->urgent_break == FALSE) {
			print_windows(self);
			usleep(100000 / (self->speed*2));
			if (self->global_counter > 10000) {
				print_winner_visual(self);
				exit(-1);
			}
		}
	}
}
