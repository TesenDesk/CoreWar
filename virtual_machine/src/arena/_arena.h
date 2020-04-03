/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arena.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:10:42 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/03 23:25:43 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ARENA_H
# define _ARENA_H

typedef struct s_player	t_player;

typedef struct			s_arena
{
	t_player		*players;
	int				nb_players;
	void			*data;
	int				size;
}						t_arena;

#endif