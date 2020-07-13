#include "operation.h"

void				operation_dispatched(t_carriage *self)
{
    void	(*operations[NUM_OF_OPERATIONS])(t_carriage *self) =
            {
			operation_live, operation_ld, operation_st,
			operation_add, operation_sub, operation_and,
			operation_or, operation_xor, operation_zjmp,
			operation_ldi, operation_sti, operation_fork,
			operation_lld, operation_lldi, operation_lfork,
			operation_aff,
            };
    operations[self->op_code - 1](self);
}