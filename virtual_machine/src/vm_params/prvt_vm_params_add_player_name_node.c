/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_vm_params_add_player_name_node.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 16:08:57 by yurezz            #+#    #+#             */
/*   Updated: 2020/08/09 15:09:38 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_vm_params.h"
#include "prvt_vmp_player.h"

void			prvt_vm_params_add_named_player_node(t_vm_params *self,
													t_vmp_player *player)
{
	t_list		*new_node;

	if ((new_node = ft_lstnew((void *)player, sizeof(*player))) == NULL)
		ft_raise(__FILE__, __LINE__, ENOMEMORY);
	ft_lstpushback(&(self->id_player_head), new_node);
	++self->nb_players;
	return ;
}
