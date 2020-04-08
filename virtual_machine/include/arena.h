/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:05:37 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 23:16:59 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

# include "libft.h"
# include "player.h"

typedef struct s_arena	t_arena;

t_arena		*arena_new(t_vm_params *params);
void		arena_destroy(t_arena **self);

void		arena_set_named_player(t_arena *self, t_player *named_player);
void		arena_set_unnamed_player(t_arena *self, t_player *unnamed_player);

#endif
