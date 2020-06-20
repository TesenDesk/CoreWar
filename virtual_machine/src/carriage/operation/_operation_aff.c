//
// Created by ikira on 6/20/20.
//


#include "_operation.h"


void            _operation_aff(t_carriage *self)
{
    int     op_len;
    int     args[1];
    char    type_codes[1];

    if (_operation_precheck_args(self, args, type_codes, 1, &op_len) == SUCCESS
        && (type_codes[0] == CODE_T_REG)) {
//        printf("%c", (char)args[0]);
    //вывести
    }
    self->arena_position += op_len % MEM_SIZE;





}
