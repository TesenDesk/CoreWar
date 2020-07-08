/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_vm_params_set_player_name.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 19:13:56 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/02 19:15:54 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_vm_params.h"

void				prvt_vm_params_set_player_name(t_vm_params *self,
													int player_name)
{
	t_vmp_player	*player;

	player = vmp_player_new(player_name, PFILE_MOCK);
	prvt_vm_params_add_named_player_node(self, player);
	return ;
}
