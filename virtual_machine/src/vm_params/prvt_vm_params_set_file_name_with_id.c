/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_vm_params_set_file_name_with_id.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 16:38:19 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/04 16:38:24 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_vm_params.h"

void				prvt_vm_params_set_file_name_with_id(t_vm_params *self,
							char *file_name)
{
	t_vmp_player	*player;
	t_list 			*lst_vmp_players;

	lst_vmp_players = self->id_player_head;
	while (lst_vmp_players && lst_vmp_players->next)
		lst_vmp_players = lst_vmp_players->next;
	player = (t_vmp_player *)lst_vmp_players->content;
	vmp_player_set_file(player, file_name);
	return ;
}
