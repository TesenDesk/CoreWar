/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vm_params_set_file_name_without_id.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 01:03:10 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/26 21:45:09 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

void					_vm_params_set_file_name_without_id(t_vm_params *self,
							char *file_name)
{
	t_vmp_player		*player;

	player = vmp_player_new(PNAME_MOCK, file_name);
	_vm_params_add_unnanmed_player_node(self, player);
	return;
}
