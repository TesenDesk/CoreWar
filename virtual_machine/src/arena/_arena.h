/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arena.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:10:42 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 23:08:21 by yurezz           ###   ########.fr       */
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
	void			*data;
	int				size;
}						t_arena;

void		_arena_set_smallest_unoccupied_name(t_arena *self);

#endif
