#include "operation.h"

void            operation_aff(t_carriage *self)
{
	t_op 		aff;

	aff = g_op[OP_AFF - 1];
    if (operation_precheck_args(self, &aff) == SUCCESS
        && aff.type_codes[ARG_1] == REG_CODE)
    {
        ; // fish
    }
    self->arena_position = (self->arena_position + aff.op_len) % MEM_SIZE;
}