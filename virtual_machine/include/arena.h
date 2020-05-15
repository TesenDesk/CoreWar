/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:05:37 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/12 17:59:46 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

typedef struct s_vm_params	t_vm_params;
typedef struct s_player		t_player;

typedef struct s_arena		t_arena;

void		arena_print_dump(t_arena *self);

t_arena		*arena_new(t_vm_params *params);
void		arena_destroy(t_arena **self);

void		arena_set_named_player(t_arena *self, t_player *named_player);
void		arena_set_unnamed_player(t_arena *self, t_player *unnamed_player);
t_list      *arena_carriage_list_new(t_arena *self);
int			arena_op_code(t_arena *self, int arena_position);

#endif
