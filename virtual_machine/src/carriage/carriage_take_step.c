#include "_carriage.h"
// return 1 - if live op else 0

int     carriage_op_code_valid(t_carriage *self)
{
    if (self->op_code >= 0x01 && self->op_code <= 0x10)
        return (TRUE);
    return (FALSE);
}

int     carriage_take_step(t_carriage *self)
{
    if (self->cycles_to_perform_op == 0)
    {
        _carriage_set_op_code(self, self->arena);
        _carriage_set_is_correct_op_code(self);
        _carriage_set_cycles_to_perform_op(self);
    }

    if (self->cycles_to_perform_op > 0)
        self->cycles_to_perform_op -= 1;
    
    if (self->cycles_to_perform_op == 0)
    {
        if (self->is_correct_op_code)
        {
            operation_perform(self);
        }
//        else
//        {
//        move carriage on one bite
//        }
    }
    return 0;
}