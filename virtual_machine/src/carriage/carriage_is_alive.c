# include "_carriage.h"

int         carriage_is_alive(t_carriage *self)
{
    if (self->last_live_cycle == 0) // cant be smaller the 0
    {
        return (FALSE);
    }
    else
    {
        self->last_live_cycle = 0;
        return (TRUE);
    }
}