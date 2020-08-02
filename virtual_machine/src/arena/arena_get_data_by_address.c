//
// Created by Jhiqui Jerde on 8/1/20.
//

#include "prvt_arena.h"

char	arena_get_data_by_address(t_arena *self, int address)
{
	return (self->data[address]);
}