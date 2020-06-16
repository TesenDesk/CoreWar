#include "_operation.h"

//don`t checked
void            _operation_fork(t_carriage *self)
{
    int         op_len;
//

    op_len = ONE_BYTE + TWO_BYTES;
    self->arena_position = op_len;
}