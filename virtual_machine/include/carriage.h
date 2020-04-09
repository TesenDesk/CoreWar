/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:09:36 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/10 00:32:37 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CARRIAGE_H
# define CARRIAGE_H

t_carriage	*carriage_new(int player_name, t_arena *arena, int arena_position);
void		carriage_destroy(t_carriage **self);

#endif