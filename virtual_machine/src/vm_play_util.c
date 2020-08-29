/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 23:20:21 by yurezz            #+#    #+#             */
/*   Updated: 2020/08/29 18:00:53 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_vm.h"
#include "prvt_arena.h"
#include "ncurses.h"
#include "prvt_carriage.h"
#include "prvt_visual.h"

static t_list	*destroy_carriage(t_list **head, t_list *current,
									t_list *previous)
{
	if (previous == NULL)
	{
		*head = current->next;
		ft_lstdelone(&current, carriage_destroy);
		return (*head);
	}
	else
	{
		previous->next = current->next;
		ft_lstdelone(&current, carriage_destroy);
		return (previous->next);
	}
}

void			destroy_dead_carriages(t_list **head, int c_t_d, int cntr,
				int verb_lvl)
{
	t_list		*current;
	t_list		*previous;

	current = *head;
	previous = NULL;
	while (current)
	{
		if (carriage_is_alive(current->content, c_t_d, cntr) == FALSE)
		{
			if (verb_lvl & 8)
				ft_printf("Process %i hasn't lived for %i cycles (CTD %i)\n",
					((t_carriage*)(current->content))->num,
					cntr - ((t_carriage*)(current->content))->last_live_cycle,
					c_t_d);
			current = destroy_carriage(head, current, previous);
		}
		else
		{
			previous = current;
			current = current->next;
		}
	}
}

void			vm_play_visual_iter(t_vm *self)
{
	self->global_counter += 1;
	self->c_counter += 1;
	self->cycles_to_dump -= 1;
}

void			my_stupid_func_fuck_norm(t_vm *self)
{
	init_curses();
	self->wins = init_wins();
	arena_players_introducing(self->arena);
	self->cycles_to_die = CYCLE_TO_DIE;
	self->c_counter = 1;
	self->global_counter = 1;
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
}
