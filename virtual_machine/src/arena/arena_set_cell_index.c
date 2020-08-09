/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_set_cell_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 15:05:02 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/09 15:05:05 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_arena.h"

void	arena_set_cell_index(t_arena *self, int mapcell_index, int index)
{
	self->colormap[mapcell_index].cell_index = index;
}
