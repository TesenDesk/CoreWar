/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_arena.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 19:08:09 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/04 19:08:35 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRVT_ARENA_H
# define PRVT_ARENA_H

# include "libft.h"
# include "op.h"
# include "errors.h"
# include "vm_params.h"
# include "player.h"
# include "carriage.h"
# include "arena.h"

# define EIGHT_BITS		8
# define DUMP_LINE_SIZE	32

typedef struct			s_arena
{
	t_player			**players;
	int					smallest_unoccupied_name;
	int					last_live_player;
	int					nb_players;
	char				*data;
	int					size;
}						t_arena;

t_player				**prvt_arena_players_new(int num_players);
void					prvt_arena_set_smallest_unoccupied_name(t_arena *self);

#endif
