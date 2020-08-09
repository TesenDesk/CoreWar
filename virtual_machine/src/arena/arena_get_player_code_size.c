/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_get_player_code_size.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 15:04:14 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/09 15:04:18 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_arena.h"

unsigned int	arena_get_player_code_size(t_arena *self, int player_index)
{
	return (self->players[player_index]->code_size);
}
