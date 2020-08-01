//
// Created by Jhiqui Jerde on 8/1/20.
//

#include "prvt_arena.h"

unsigned int	arena_get_player_code_size(t_arena *self, int player_index)
{
	return (self->players[player_index]->code_size);
}