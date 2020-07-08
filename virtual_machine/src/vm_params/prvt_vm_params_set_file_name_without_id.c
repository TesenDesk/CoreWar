/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_vm_params_set_file_name_without_id.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 16:33:55 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/04 16:35:12 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_vm_params.h"

void				prvt_vm_params_set_file_name_without_id(t_vm_params *self,
															char *file_name)
{
	t_vmp_player	*player;

	player = vmp_player_new(PNAME_MOCK, file_name);
	prvt_vm_params_add_unnamed_player_node(self, player);
	return ;
}
