/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_arena.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 19:08:09 by cmissy            #+#    #+#             */
/*   Updated: 2020/08/09 15:01:00 by ftothmur         ###   ########.fr       */
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
# include "visual.h"
# include "prvt_player.h"

# define EIGHT_BITS		8
# define DUMP_LINE_SIZE	64

typedef struct			s_arena
{
	t_player			**players;
	int					smallest_unoccupied_name;
	int					last_live_player;
	int					nb_players;
	char				*data;
	t_color_mapcell		colormap[MEM_SIZE];
	int					carriage_num[4];
	int					color_is_set;
	int					size;
}						t_arena;

t_player				**prvt_arena_players_new(int num_players);
void					prvt_arena_set_smallest_unoccupied_name(t_arena *self);

// TODO: 	t_color_mapcell     colormap[MEM_SIZE];
/*
** t_color_mapcell должен быть приватным, но для работы с массмвом нужно знать
** размер его элементов, но это недопустимо для ООП. Выход -- заменить ё
** объявлением типа указателей на войддля данного класа, но заццепленность кода
** пока это не позволяет
*/

#endif
