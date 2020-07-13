/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmp_player.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 19:32:47 by yurezz            #+#    #+#             */
/*   Updated: 2020/07/13 16:06:10 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VMP_PLAYER_H

# define VMP_PLAYER_H

# include "file.h"

# define PNAME_MOCK			0
# define PFILE_MOCK			(void *)0

typedef struct s_vmp_player	t_vmp_player;

t_vmp_player	*vmp_player_new(int player_name, char *player_file);
void			vmp_player_destroy(t_vmp_player **self);
void			vmp_player_set_file(t_vmp_player *self, char *file_name);
int				vmp_player_name(t_vmp_player *self);
t_i_file		*vmp_player_file(t_vmp_player *self);

#endif
