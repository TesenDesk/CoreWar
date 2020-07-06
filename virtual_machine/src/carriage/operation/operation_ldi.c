#include "operation.h"

static void                print_op_log(t_carriage *self, int *args)
{
    printf("P %4i | ldi %i %i r%i\n", self->num, args[0], args[1], args[2] + 1);
    printf("       | -> load from %i + %i = %i (with pc and mod %i)\n",
            args[0], args[1], args[0] + args[1], self->arena_position + (args[0] + args[1]) % IDX_MOD);
}

void operation_ldi(t_carriage *self)
{
	static t_op		op;

	op = g_op[OP_LLDI - 1];

    if (operation_precheck_args(self, &op) == SUCCESS
        && (op.type_codes[ARG_1] == REG_CODE || op.type_codes[ARG_1] == DIR_CODE ||
			op.type_codes[ARG_1] == IND_CODE)
        && (op.type_codes[ARG_2] == REG_CODE || op.type_codes[ARG_2] == DIR_CODE)
        && op.type_codes[ARG_3] == REG_CODE)
    {
        if (op.type_codes[ARG_1] == REG_CODE)
			op.args[ARG_1] = self->registers[op.args[ARG_1]];
        else if (op.type_codes[ARG_1] == IND_CODE)
			op.args[ARG_1] = arena_get_n_bytes_from(self->arena,
            		self->arena_position + op.args[ARG_1] % IDX_MOD, FOUR_BYTES);

        if (op.type_codes[ARG_2] == REG_CODE)
			op.args[ARG_2] = self->registers[op.args[ARG_2]];

print_op_log(self, op.args);

        self->registers[op.args[ARG_3]] = arena_get_n_bytes_from(self->arena,
        		self->arena_position + (op.args[ARG_1] + op.args[ARG_2]) % IDX_MOD,
        		FOUR_BYTES);
    }
    self->arena_position = (self->arena_position + op.op_len) % MEM_SIZE;
}