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
	}
}
