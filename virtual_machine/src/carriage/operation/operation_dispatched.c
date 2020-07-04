#include "prvt_operation.h"

void				operation_dispatched(t_carriage *self)
{
    void	(*operations[NUMBER_OF_OPERATIONS])(t_carriage *self) =
            {
		            prvt_operation_live,
		            prvt_operation_ld,
		            prvt_operation_st,
		            prvt_operation_add,
		            prvt_operation_sub,
		            prvt_operation_and,
		            prvt_operation_or,
		            prvt_operation_xor,
		            prvt_operation_zjmp,
		            prvt_operation_ldi,
		            prvt_operation_sti,
		            prvt_operation_fork,
		            prvt_operation_lld,
		            prvt_operation_lldi,
		            prvt_operation_lfork,
		            prvt_operation_aff,
            };
    operations[self->op_code - 1](self);
}