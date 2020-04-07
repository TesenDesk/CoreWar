/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmp_player.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 19:32:47 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/07 13:03:32 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_PLAYER_H

# define VM_PLAYER_H

# define PNAME_MOCK	0
# define PFILE_MOCK	(void *)0

typedef struct s_vmp_player t_vmp_player;

t_vmp_player	*vmp_player_ctor(int player_name, char *player_file);
void			vmp_player_dtor(t_vmp_player **self);

void			vmp_player_set_file_name(t_vmp_player *self, char *file_name);
void			vmp_player_check_if_readable(t_vmp_player *self);
void			vmp_player_open(t_vmp_player *self);
void			vmp_player_close(t_vmp_player *self);

#endif
