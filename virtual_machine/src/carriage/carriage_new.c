/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:28:46 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/10 00:00:07 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "_carriage.h"

t_carriage		*carriage_new(int player_name, t_arena *arena,
                             int arena_position, int num)
{
    t_carriage	*self;

    if ((self = (t_carriage *)ft_memalloc(sizeof(*self))) == NULL)
        raise(__FILE__, __LINE__, ENOMEMORY);
    self->num = num;
    self->arena = arena;
    self->player_name = player_name;
    self->registers[0] = -self->player_name;
    if (arena_position < 0)
        arena_position = MEM_SIZE + arena_position % MEM_SIZE;
    else if (arena_position >= MEM_SIZE)
        arena_position = arena_position % MEM_SIZE;
    self->arena_position = arena_position;
    return (self);
}
