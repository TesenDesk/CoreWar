//
// Created by Jhiqui Jerde on 8/1/20.
//

#include "prvt_arena.h"

int		arena_get_cell_index(t_arena *self, int index)
{
	return (self->colormap[index].cell_index);
}