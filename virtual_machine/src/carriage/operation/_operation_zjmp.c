#include "_operation.h"

//don`t checked
void                    _operation_zjmp(t_carriage *self)
{
    int     op_len;
    int     arg;

    op_len = ONE_BYTE + TWO_BYTES;
    if (self->carry == 1)
    {
        arg = arena_get_n_bytes_from(self->arena, self->arena_position + ONE_BYTE, TWO_BYTES) % IDX_MOD;
        self->arena_position = (self->arena_position + arg) % MEM_SIZE;
    }
    else
        self->arena_position = (self->arena_position + op_len) % MEM_SIZE;
}