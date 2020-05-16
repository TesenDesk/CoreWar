/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:10:07 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/26 21:44:10 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

#include "vmp_player.h"

typedef struct s_player	t_player;

void	    	player_set_name(t_player *self, int name);

int				player_name(t_player *self);
t_player		*player_new(t_vmp_player *vmp_player);
void			player_destroy(t_player **self);
//void            player_introducing(t_player **self);

#endif
