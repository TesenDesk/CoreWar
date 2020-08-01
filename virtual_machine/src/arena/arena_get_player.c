//
// Created by Jhiqui Jerde on 8/1/20.
//

#include "prvt_arena.h"

t_player	*arena_get_player(t_arena *self, int index)
{
	return (self->players[index]);
}