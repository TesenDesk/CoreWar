#include "operation.h"

static void                print_op_log(t_carriage *self, int *args)
{
    printf("P %4i | lld %i r%i\n", self->num, args[ARG_1], args[ARG_2] + 1);
}

void operation_lld(t_carriage *self)
{
	static t_op 	op;

	op = g_op[OP_LLD];

    if (operation_precheck_args(self, &op) == SUCCESS
        && (op.type_codes[ARG_1] == IND_CODE || op.type_codes[ARG_1] == DIR_CODE)
        && op.type_codes[ARG_2] == REG_CODE)
    {
        if (op.type_codes[ARG_1] == IND_CODE)
			op.args[ARG_1] = arena_get_n_bytes_from(self->arena, self->arena_position + op.args[ARG_1], TWO_BYTES); // like original vm
//            args[0] = arena_get_n_bytes_from(self->arena, self->arena_position + args[0], FOUR_BYTES); // need to be

		print_op_log(self, op.args);

        if ((self->registers[op.args[ARG_2]] = op.args[ARG_1]) == 0)
            self->carry = TRUE;
        else
            self->carry = FALSE;
    }
    self->arena_position = (self->arena_position + op.op_len) % MEM_SIZE;
}