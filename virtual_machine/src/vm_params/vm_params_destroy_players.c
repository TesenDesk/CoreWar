/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_params_destroy_players.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 12:57:53 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/07 16:59:43 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

static void			_vm_params_destroy_player(void *_player, size_t mock)
{
	t_vmp_player	*player;

	player = (t_vmp_player *)_player;
	vmp_player_dtor(&player);
	(void)mock;
	return;
}

void				vm_params_destroy_players_lists(t_vm_params *self)
{
	ft_lstdel(&self->id_player_head, _vm_params_destroy_player);
	ft_lstdel(&self->noid_player_head, _vm_params_destroy_player);
	return;
}
