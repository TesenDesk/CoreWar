/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:10:07 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 23:15:07 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

#include "vmp_player.h"

typedef struct s_player	t_player;

void		player_set_name(t_player *self, int name);
int			player_name(t_player *self);

t_player	*player_new(t_vmp_player *vmp_player);
void		player_destroy(t_player **self);

#endif
