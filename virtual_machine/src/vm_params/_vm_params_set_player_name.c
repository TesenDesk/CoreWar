/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vm_params_set_player_name.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 00:43:59 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/26 20:31:35 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

void				_vm_params_set_player_name(t_vm_params *self,
						 int player_name_str)
{
	t_vmp_player	*player;
	
	player = vmp_player_new(player_name, PFILE_MOCK);
	_vm_params_add_named_player_node(self, (void*)player);
	return;
}
