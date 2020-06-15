#include "_arena.h"

void        arena_set_last_live_player(t_arena *self, int player_num)
{
    self->last_live_player = player_num;
}