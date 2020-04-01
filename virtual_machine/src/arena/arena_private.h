/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:10:42 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/01 20:53:25 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_PRIVATE_H
# define ARENA_PRIVATE_H

typedef struct s_player	t_player;

typedef struct			s_arena
{
	t_player		*players;
	int				nb_players;
	void			*data;
	int				size;
}						t_arena;

#endif