#include "_operation.h"

//dont checked
void            _operation_aff(t_carriage *self)
{
    int         op_len;
    int         arg;
    char        type_code;


    if (_operation_precheck_args(self, &arg, &type_code, 1, &op_len) == SUCCESS
        && type_code == CODE_T_REG)
    {
        arg = 1; // fish
    }
    self->arena_position = (self->arena_position + op_len) % MEM_SIZE;
}