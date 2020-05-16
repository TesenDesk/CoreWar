#include "_arena.h"

t_player     **arena_players(t_arena *self)
{
    return (self->players);
}