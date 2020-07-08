#include "operation.h"

static void                perform_op(t_carriage *self, int *args)
{
	if (vm_verbosity_lvl() & 4)
	{
		printf("P %4i | xor %i %i r%i\n", self->num, args[ARG_1], args[ARG_2],
         args[ARG_3] + 1);
	}
}

void operation_xor(t_carriage *self)
{
	t_op 	op;

	op = g_op[OP_XOR - 1];
    if (operation_precheck_args(self, &op) == SUCCESS)
    {
        if (op.type_codes[ARG_1] == REG_CODE)
			op.args[ARG_1] = self->registers[op.args[ARG_1]];
        else if (op.type_codes[ARG_1] == IND_CODE)
			op.args[ARG_1] = arena_get_n_bytes_from(self->arena,self->arena_position + op.args[ARG_1] % IDX_MOD, FOUR_BYTES);
        if (op.type_codes[ARG_2] == REG_CODE)
			op.args[ARG_2] = self->registers[op.args[ARG_2]];
        else if (op.type_codes[ARG_2] == IND_CODE)
			op.args[ARG_2] = arena_get_n_bytes_from(self->arena,self->arena_position + op.args[ARG_2] % IDX_MOD, FOUR_BYTES);
		perform_op(self, op.args);
        if ((self->registers[op.args[ARG_3]] = op.args[ARG_1] ^ op.args[ARG_2]) == 0)
            self->carry = TRUE;
        else
            self->carry = FALSE;
    }
    self->arena_position = (self->arena_position + op.op_len) % MEM_SIZE;
}