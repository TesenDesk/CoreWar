/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vm_params_add_player_node.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 01:00:49 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/26 04:17:08 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"
#include "vmp_player.h"
<<<<<<< HEAD
#include "player.h"
=======
#include "./vmp_player/file/_file.h"
>>>>>>> 5e87aa81da8044c119c7391fd8d16694431cd531


//void				_vm_params_add_unnamed_player_node(t_vm_params *self,
//						t_file *player)
void				_vm_params_add_unnamed_player_node(t_vm_params *self,
<<<<<<< HEAD
 						t_player *player)
=======
						tt_file *player)
>>>>>>> 5e87aa81da8044c119c7391fd8d16694431cd531
{
	t_list				*new_node;

//	if ((new_node = ft_lstnew((void *)player, sizeof(*player))) == NULL)
	if ((new_node = ft_lstnew((void *)player, sizeof(*player))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	ft_lstadd(&self->noid_player_head, new_node);
	++self->nb_players;
	return ;
}
<<<<<<< HEAD
return;
=======
>>>>>>> 5e87aa81da8044c119c7391fd8d16694431cd531
