#include "_operation.h"

static void                perform_op(t_carriage *self, int arg)
{
    if (self->carry)
        printf("P%5i | zjmp %i OK\n", self->num, arg);
    else
        printf("P%5i | zjmp %i FAILED\n", self->num, arg);
}

void                    _operation_zjmp(t_carriage *self)
{
    int     op_len;
    int     arg;

    op_len = ONE_BYTE + TWO_BYTES;
    arg = arena_get_n_bytes_from(self->arena, self->arena_position + ONE_BYTE, TWO_BYTES) % IDX_MOD;
    if (self->carry == 1)
        self->arena_position = (self->arena_position + arg) % MEM_SIZE;
    else
        self->arena_position = (self->arena_position + op_len) % MEM_SIZE;

    perform_op(self, arg);
}