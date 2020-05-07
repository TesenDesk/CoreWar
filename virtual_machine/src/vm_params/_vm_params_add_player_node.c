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
#include "./vmp_player/file/_file.h"

<<<<<<< HEAD
=======
// void				_vm_params_add_unnamed_player_node(t_vm_params *self,
// 						t_player *player)
>>>>>>> e3e25fe0ac3684476028641a79df83acff7a3173
void				_vm_params_add_unnamed_player_node(t_vm_params *self,t_vmp_player *player)
{
    t_list				*new_node;

<<<<<<< HEAD
    if ((new_node = ft_lstnew((void *)player, sizeof(*player))) == NULL)
        raise(__FILE__, __LINE__, ENOMEMORY);
    ft_lstadd(&self->noid_player_head, new_node);
    ++self->nb_players;
    return ;
=======
if ((new_node = ft_lstnew((void *)player, sizeof(*player))) == NULL)
	raise(__FILE__, __LINE__, ENOMEMORY);
ft_lstadd(&self->noid_player_head, new_node);
++self->nb_players;
return ;
>>>>>>> e3e25fe0ac3684476028641a79df83acff7a3173
}
