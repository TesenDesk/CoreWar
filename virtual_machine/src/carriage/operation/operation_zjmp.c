#include "operation.h"

static void                print_op_log(t_carriage *self, int arg)
{
	if (vm_verbosity_lvl() == 4)
	{
		if (self->carry)
			printf("P %4i | zjmp %i OK\n", self->num, arg);
		else
			printf("P %4i | zjmp %i FAILED\n", self->num, arg);
	}
}

void        operation_zjmp(t_carriage *self)
{
	t_op 	op;
    int     arg;

    op = g_op[OP_ZJMP - 1];
    op.op_len = OP_CODE_SIZE + op.t_dir_size;
    arg = arena_get_n_bytes_from(self->arena, self->arena_position + OP_CODE_SIZE, op.t_dir_size);
    if (self->carry == 1)
        self->arena_position = (self->arena_position + arg  % IDX_MOD) % MEM_SIZE;
    else
        self->arena_position = (self->arena_position + op.op_len) % MEM_SIZE;
    if (self->arena_position < 0)
        self->arena_position = MEM_SIZE + (self->arena_position % MEM_SIZE);
    print_op_log(self, arg);
}