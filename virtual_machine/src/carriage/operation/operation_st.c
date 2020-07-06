#include "operation.h"

static void                print_op_log(t_carriage *self, int *args, char *type_codes)
{
    if (type_codes[1] == REG_CODE)
        printf("P %4i | st r%i %i\n", self->num, args[ARG_1] + 1,
             args[ARG_2] + 1);
    else
        printf("P %4i | st r%i %i\n", self->num, args[ARG_1] + 1, args[ARG_2]);
}

void operation_st(t_carriage *self)
{
	static t_op op;

	op = g_op[OP_ST];
    if (operation_precheck_args(self, &op) == SUCCESS
        && op.type_codes[ARG_1] == REG_CODE
        && (op.type_codes[ARG_2] == REG_CODE || op.type_codes[ARG_2] == IND_CODE))
    {

print_op_log(self, op.args, op.type_codes);

        if (op.type_codes[ARG_2] == IND_CODE)
            arena_write_four_bytes_to_data(self->arena, self->arena_position
                                                          + op.args[ARG_2] %
                                                                IDX_MOD,
                                         self->registers[op.args[ARG_1]]);
        else
            self->registers[op.args[ARG_2]] = self->registers[op.args[ARG_1]];
    }
    self->arena_position = (self->arena_position + op.op_len) % MEM_SIZE;
}