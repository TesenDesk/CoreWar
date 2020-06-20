#include "_operation.h"

void            _operation_sub(t_carriage *self)
{
    //    need change "3" to constant later
    int     op_len;
    int     args[3];
    char    type_codes[3];
    int     sub;

    if (_operation_precheck_args(self, args, type_codes, 3, &op_len) == SUCCESS
        && type_codes[0] == CODE_T_REG
        && type_codes[1] == CODE_T_REG
        && type_codes[2] == CODE_T_REG)
    {
        sub = self->registers[args[0]] - self->registers[args[1]];
        if ((self->registers[args[2]] = sub) == 0)
            self->carry = 1;
        else
            self->carry = 0;
    }
    if (op_len <= 0)
    {
        printf("SOMETHING WRONG WITH OP_LEN IN _OPERATION_SUB\n");
        exit(1);
    }
    self->arena_position = (self->arena_position + op_len) % MEM_SIZE;
}