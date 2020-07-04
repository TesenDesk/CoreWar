#include "prvt_operation.h"

static void                print_op_log(t_carriage *self, int arg)
{
    if (self->carry)
        printf("P %4i | zjmp %i OK\n", self->num, arg);
    else
        printf("P %4i | zjmp %i FAILED\n", self->num, arg);
}

void                    prvt_operation_zjmp(t_carriage *self)
{
    int     op_len;
    int     arg;

    op_len = ONE_BYTE + TWO_BYTES;
    arg = arena_get_n_bytes_from(self->arena, self->arena_position + ONE_BYTE, TWO_BYTES);
    if (self->carry == 1)
        self->arena_position = (self->arena_position + arg  % IDX_MOD) % MEM_SIZE;
    else
        self->arena_position = (self->arena_position + op_len) % MEM_SIZE;

    if (self->arena_position < 0)
        self->arena_position = MEM_SIZE + (self->arena_position % MEM_SIZE);

print_op_log(self, arg);
}