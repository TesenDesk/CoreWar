/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_params_destroy_players.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 12:57:53 by yurezz            #+#    #+#             */
/*   Updated: 2020/07/02 18:32:46 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

static void			prvt_vm_params_destroy_player(void *prvt_player,
														size_t mock)
{
	t_vmp_player	*player;

	player = (t_vmp_player *)prvt_player;
	vmp_player_destroy(&player);
	(void)mock;
	return ;
}

void				vm_params_destroy_players_lists(t_vm_params *self)
{
	ft_lstdel(&self->id_player_head, prvt_vm_params_destroy_player);
	ft_lstdel(&self->noid_player_head, prvt_vm_params_destroy_player);
	return ;
}
