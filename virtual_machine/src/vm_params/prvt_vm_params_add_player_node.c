/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_vm_params_add_player_node.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 01:00:49 by yurezz            #+#    #+#             */
/*   Updated: 2020/08/09 15:11:50 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_vm_params.h"
#include "prvt_vmp_player.h"

void			prvt_vm_params_add_unnamed_player_node(t_vm_params *self,
												t_vmp_player *player)
{
	t_list		*new_node;

	if ((new_node = ft_lstnew((void *)player, sizeof(*player))) == NULL)
		ft_raise(__FILE__, __LINE__, ENOMEMORY);
	ft_lstpushback(&(self->noid_player_head), new_node);
	++self->nb_players;
	return ;
}
