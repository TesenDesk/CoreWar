#include "operation.h"

static void                print_op_log(t_carriage *self, int *args)
{
	if (vm_verbosity_lvl() & 4)
	{
		printf("P %4i | lldi %i %i r%i\n", self->num, args[ARG_1], args[ARG_2],
				args[ARG_3] + 1);
		printf("       | -> load from %i + %i = %i (with pc %i)\n",
			   args[ARG_1], args[ARG_2], args[ARG_1] + args[ARG_2],
			   self->arena_position +
			   args[ARG_1] + args[ARG_2]);
	}
}

void operation_lldi(t_carriage *self)
{
    static t_op		op;
    int     arg;

    op = g_op[OP_LLDI - 1];
    if (operation_precheck_args(self, &op) == SUCCESS)
    {
        if (op.type_codes[ARG_1] == REG_CODE)
			op.args[ARG_1] = self->registers[op.args[ARG_1]];
        else if (op.type_codes[ARG_1] == IND_CODE)
			op.args[ARG_1] = arena_get_n_bytes_from(self->arena, self->arena_position + op.args[ARG_1] % IDX_MOD, FOUR_BYTES);
        if (op.type_codes[1] == REG_CODE)
			op.args[ARG_1] = self->registers[op.args[ARG_1]];

print_op_log(self, op.args);

        arg = arena_get_n_bytes_from(self->arena, self->arena_position +
        (op.args[ARG_1] + op.args[ARG_2]), FOUR_BYTES);

        if ((self->registers[op.args[ARG_3]] = arg) == 0)
            self->carry = TRUE;
        else
            self->carry = FALSE;
    }
    self->arena_position = (self->arena_position + op.op_len) % MEM_SIZE;
}