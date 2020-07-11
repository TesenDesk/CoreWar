/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:09:36 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/12 17:38:42 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CARRIAGE_H
# define CARRIAGE_H

typedef struct s_arena		t_arena;
typedef struct s_carriage	t_carriage;

t_carriage	*carriage_new(int player_name, t_arena *arena, int arena_position, int num);
void         carriage_take_step(t_carriage *self);
void		carriage_destroy(void *self, size_t size);
int         carriage_is_alive(t_carriage *self, int cycles_to_die, int counter);

#endif
