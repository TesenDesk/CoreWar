#include "_arena.h"

int             arena_is_turnable(t_arena *self)
{
    if (self->dump_cycles
        && self->nb_of_cycles == self->dump_cycles)
    {
        arena_print_dump(self);
        return FAILURE;
    }
    return SUCCESS;
}