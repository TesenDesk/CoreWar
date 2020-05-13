    /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arena.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:10:42 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/24 19:40:33 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ARENA_H
# define _ARENA_H

# include "libft.h"
# include "op.h"
# include "errors.h"
# include "arena.h"
# include "vm_params.h"
# include "player.h"


typedef struct			s_arena
{
	t_player		**players;
	int				smallest_unoccupied_name;
	int				nb_players;
	int             nb_of_cycles;
	void			*data;
	int				size;
	int 			dump_cycles;
}						t_arena;


t_player	**_arena_players_new(int num_players);
void		_arena_set_smallest_unoccupied_name(t_arena *self);

#endif
