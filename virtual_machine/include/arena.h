/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:05:37 by yurezz            #+#    #+#             */
/*   Updated: 2020/07/13 12:52:43 by cmissy           ###   ########.fr       */
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
t_list		*arena_carriage_list_new(t_arena *self);
t_player	**arena_players(t_arena *self);
int			arena_nb_players(t_arena *self);
int			arena_op_code(t_arena *self, int arena_position);
void		arena_players_introducing(t_arena *self);
int			arena_get_n_bytes_from(t_arena *self, int pos, int num_of_bytes);
void		arena_set_last_live_player(t_arena *self, int player_num);
void		arena_print_winner(t_arena *self);
void		arena_write_four_bytes_to_data(t_arena *self, int pos,
											int new_data);

#endif
