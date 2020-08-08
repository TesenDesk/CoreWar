/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:10:07 by yurezz            #+#    #+#             */
/*   Updated: 2020/07/13 12:46:47 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "vmp_player.h"

typedef struct s_player	t_player;

void			player_set_name(t_player *self, int name);

int				p_name(t_player *self);
t_player		*player_new(t_vmp_player *vmp_player);
void			player_destroy(t_player **self);
void			player_introducing(t_player *players);
void			player_print_winner(t_player *self);
char			*player_code(t_player *self);
int				player_code_size(t_player *self);
void			player_live_verbosity(t_player *self);

char			*player_get_text_name(t_player *player);
char			*player_get_text_comment(t_player *player);
int				player_get_name(t_player *player);

#endif
