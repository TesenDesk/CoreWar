/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vm_params_set_player_name.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 00:43:59 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 22:49:58 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

void				_vm_params_set_player_name(t_vm_params *self,
						char *player_name_str)
{
	int					player_name;
	t_vmp_player		*player;
	
	if (ft_strint_ou_flow(player_name_str, player_name) == FAILURE)
		raise(__FILE__, __LINE__, EINTOUFLOW);
	player = vmp_player_new(player_name, PFILE_MOCK);
	_vm_params_add_named_player_node(self, player);
	return;
}
