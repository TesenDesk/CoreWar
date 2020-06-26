#include "_arena.h"

void        arena_print_winner(t_arena *self)
{
    player_print_winner(self->players[self->last_live_player - 1]);
}