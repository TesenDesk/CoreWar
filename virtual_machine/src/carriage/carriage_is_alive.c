# include "_carriage.h"

int         carriage_is_alive(t_carriage *self, int cycles_to_die, int counter)
{
    if (cycles_to_die <= 0
    || (counter - self->last_live_cycle) >= cycles_to_die)
        return (FALSE);
    else
        return (TRUE);
}