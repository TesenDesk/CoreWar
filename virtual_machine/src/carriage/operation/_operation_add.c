#include "_operation.h"

static void                perform_op(t_carriage *self, int *args)
{
    printf("P%5i | add r%i r%i r%i\n", self->num, args[0] + 1, args[1] + 1, args[2] + 1);
}
void            _operation_add(t_carriage *self)
{
    //    need change "3" to constant later
    int     op_len;
    int     args[3];
    char    type_codes[3];
    int     sum;

    if (_operation_precheck_args(self, args, type_codes, 3, &op_len) == SUCCESS
        && type_codes[0] == CODE_T_REG
        && type_codes[1] == CODE_T_REG
        && type_codes[2] == CODE_T_REG)
    {
        sum = self->registers[args[0]] + self->registers[args[1]];
        if ((self->registers[args[2]] = sum) == 0)
            self->carry = 1;
        else
            self->carry = 0;
        perform_op(self, args);
    }
    if (op_len <= 0)
    {
        printf("SOMETHING WRONG WITH OP_LEN IN _OPERATION_ADD\n");
        exit(1);
    }
    self->arena_position = (self->arena_position + op_len) % MEM_SIZE;
}