/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmp_player.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 19:32:47 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/26 21:35:26 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_PLAYER_H

# define VM_PLAYER_H

# define PNAME_MOCK	0
# define PFILE_MOCK	(void *)0

#include "file.h"
typedef struct s_vmp_player t_vmp_player;


t_vmp_player	*vmp_player_new(int player_name, char *player_file);
void			vmp_player_destroy(t_vmp_player **self);
void			vmp_player_set_file(t_vmp_player *self, char *file_name);
int             vmp_player_name(t_vmp_player *self);
tt_file			*vmp_player_file(t_vmp_player *self);
	

#endif