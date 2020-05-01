/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vm_params_set_file_name_with_id.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 00:47:10 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/26 21:44:34 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"
#include "vmp_player.h"

void				_vm_params_set_file_name_with_id(t_vm_params *self,
							char *file_name)
{
	t_vmp_player	*player;

	player = (t_vmp_player *)self->id_player_head->content;
	vmp_player_set_file(player, file_name);
	return;
}
