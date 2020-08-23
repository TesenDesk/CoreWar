/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_set_store_index.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 15:05:35 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/09 15:05:37 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_arena.h"

void	arena_set_store_index(t_arena *self, int mapcell_index, int index)
{
	self->colormap[mapcell_index].store_index = index;
}
