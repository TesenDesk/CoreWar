/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_params_add_player_name_node.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 16:08:57 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/07 16:27:42 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"


void			_vm_params_add_named_player_node(t_vm_params *self,
					void *player)
{
	t_list		*new_node;

	if ((new_node = ft_lstnew((void *)player, sizeof(*player))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	ft_lstadd(&self->id_player_head, new_node);
	++self->nb_players;
	return;
}