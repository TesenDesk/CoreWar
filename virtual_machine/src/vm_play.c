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
#include "arena/_arena.h"

void            destroy_dead_carriages(t_list **head, int cycles_to_die, int counter)
{
    t_list      *current;
    t_list      *previous;

    current = *head;
    previous = NULL;
    while (current)
    {
        if (carriage_is_alive(current->content, cycles_to_die, counter) == FALSE)
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

int             vm_check(t_vm *self)
{
    destroy_dead_carriages(&(self->carriage_head), self->cycles_to_die, self->global_counter);
    if (self->carriage_head == NULL) // all carriages dead
        return (FAILURE);

    if (self->num_checks >= MAX_CHECKS // cycles_to_die менялась MAX_CHECKS проверок(vm_check) назад
            || self->num_of_live_ops >= NBR_LIVE) // число операций live слишко большое
    {
        self->num_checks = 0;
        self->cycles_to_die -= CYCLE_DELTA;
    }
    self->num_checks += 1;
    self->num_of_live_ops = 0;
    self->cycles_counter = 0;
    return (SUCCESS);
}

void            vm_next_cycle(t_vm *self)
{
    t_list      *list;

    list = self->carriage_head;
    while (list)
    {
        carriage_take_step(list->content);
        list = list->next;
    }
}

void 		    vm_play(t_vm *self)
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
            break;
        }
        vm_next_cycle(self);
        if (self->cycles_to_die <= self->cycles_counter)
        {
            if (vm_check(self) == FAILURE) {
                arena_print_winner(self->arena);
                break;
            }
        }
        self->global_counter += 1;
        self->cycles_counter += 1;
        self->cycles_to_dump -= 1;
    }
}
