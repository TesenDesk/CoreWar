/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vm_params_set_file_name_without_id.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 01:03:10 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/06 01:03:37 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

void					_vm_params_set_file_name_without_id(t_vm_params *self,
							char *file_name)
{
	t_vmp_player		*player;

	player = vmp_player_ctor(PNAME_MOCK, file_name);
	vmp_utils_check_if_file_is_available(file_name);
	vm_params_add_player_node(self, player);
	return;
}
