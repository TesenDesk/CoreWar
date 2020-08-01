//
// Created by Jhiqui Jerde on 8/1/20.
//

#include "prvt_arena.h"

void	arena_set_carriage_num(t_arena *self, int index, int carriage_num)
{
	self->carriage_num[index] = carriage_num;
}