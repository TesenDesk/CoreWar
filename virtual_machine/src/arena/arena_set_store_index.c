//
// Created by Jhiqui Jerde on 8/1/20.
//

#include "prvt_arena.h"

void	arena_set_store_index(t_arena *self, int mapcell_index, int index)
{
	self->colormap[mapcell_index].store_index = index;
}