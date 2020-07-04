/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_params_add_player_name_node.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 16:08:57 by yurezz            #+#    #+#             */
/*   Updated: 2020/07/02 18:58:09 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_vm_params.h"

void			prvt_vm_params_add_named_player_node(t_vm_params *self,
					t_vmp_player *player)
{
	t_list		*new_node;

	if ((new_node = ft_lstnew((void *)player, sizeof(*player))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	ft_lstpushback(&(self->id_player_head), new_node);
	++self->nb_players;
	return ;
}
