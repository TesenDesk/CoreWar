/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vm_params_set_player_name.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 00:43:59 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/06 01:11:25 by yurezz           ###   ########.fr       */
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
	player = vmp_player_ctor(player_name, PFILE_MOCK);
	vm_params_add_player_name_node(self, player);
	return;
}
