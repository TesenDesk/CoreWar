/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vm_params_add_player_node.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 01:00:49 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/06 01:01:20 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

void				_vm_params_add_player_node(t_vm_params *self,
							char *file_name)
{
	t_list				*new_node;

	if ((new_node = ft_lstnew((void *)file_name, ft_strlen(file_name))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	ft_lstadd(&self->id_player_head, new_node);
	return;
}
