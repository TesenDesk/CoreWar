/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vm_params_add_player_node.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 01:00:49 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/07 16:22:24 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

void				_vm_params_add_unnamed_player_node(t_vm_params *self,
						t_vmp_player *player)
{
	t_list				*new_node;

//	if ((new_node = ft_lstnew((void *)player, sizeof(*player))) == NULL)
//		raise(__FILE__, __LINE__, ENOMEMORY);
//	ft_lstadd(&self->noid_player_head, new_node);
	++self->nb_players;
	return;
}
