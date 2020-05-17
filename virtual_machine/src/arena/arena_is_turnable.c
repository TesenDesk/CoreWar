#include "_arena.h"

int             arena_is_turnable(t_arena *self)
{
//    if (self->dump_cycles && self->nb_of_cycles >= self->dump_cycles)
//    {
//        arena_print_dump(self);
//        return FAILURE;
//    }
//    else if (carriages_check_win())
//    {
        player_print_winner(self->players[0]);
//        player_print_winner(self->last_live_player);
        return FAILURE;
//    }
}