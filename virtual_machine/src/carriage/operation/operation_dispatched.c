#include "_operation.h"

void				operation_dispatched(t_carriage *self)
{
    void	(*operations[NUMBER_OF_OPERATIONS])(t_carriage *self) =
            {
//                    _operation_mock,
                    _operation_live,
                    _operation_ld,
                    _operation_st,
                    _operation_add,
                    _operation_sub,
                    _operation_and,
                    _operation_or,
                    _operation_xor,
                    _operation_zjmp,
//                    _operation_ldi,
//                    _operation_sti,
//                    _operation_fork,
//                    _operation_lld,
//                    _operation_lldi,
//                    _operation_lfork,
//                    _operation_aff,
            };
    operations[self->op_code](self);
}