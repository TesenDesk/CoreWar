/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:09:36 by yurezz            #+#    #+#             */
/*   Updated: 2020/08/08 18:28:12 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CARRIAGE_H
# define CARRIAGE_H

typedef struct s_arena		t_arena;
typedef struct s_carriage	t_carriage;

t_carriage	*carriage_new(int p_name, t_arena *arena, int arena_position,
							int num);
void		carriage_take_step(t_carriage *self);
void		carriage_destroy(void *self, size_t size);
int			carriage_is_alive(t_carriage *self, int cycles_to_die, int counter);

int			carriage_get_arena_position(t_carriage *self);
int			carriage_get_player_name(t_carriage *self);
int			carriage_get_stor_pos(t_carriage *self);

#endif
