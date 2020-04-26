/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vm_params_set_file_name_with_id.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 00:47:10 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/26 04:37:42 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

// void				_vm_params_set_file_name_with_id(t_vm_params *self,
// 							char *file_name)
void				_vm_params_set_file_name_with_id(t_vm_params *self,
							int *file_name)
{
	// t_vmp_player	*player;
	t_file	*player;

	player = (t_file *)self->id_player_head->content;
	vmp_player_set_file(player, file_name);
	return;
}
