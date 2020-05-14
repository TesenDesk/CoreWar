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
#include "carriage/_carriage.h"
#include "arena/_arena.h"
#include "errors.h"

static t_list *carriages_new( int players_num)
{
	int 	cur_player;
	t_list	*new_car;
	t_list	*core;

	cur_player = 1;
//	if (!(ft_lstnew(carriage_new())))

	while(cur_player <= players_num)
	{
//		if (!(ft_lstnew()))
		++cur_player;


	}

}

void 		vm_play(t_vm *self)
{
	t_list	*carriages;

	if (!(carriages_new(self->arena->nb_players)))
		raise(__FILE__, __LINE__, ENOMEMORY);




}