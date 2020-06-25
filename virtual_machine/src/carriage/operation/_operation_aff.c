#include "_operation.h"

//dont checked
void            _operation_aff(t_carriage *self)
{
    int         op_len;


    op_len = ONE_BYTE + ONE_BYTE + ONE_BYTE;
    self->arena_position = (self->arena_position + op_len) % MEM_SIZE;
}