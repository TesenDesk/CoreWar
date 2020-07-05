#include "prvt_operation.h"

static void                print_op_log(t_carriage *self, int *args)
{
    printf("P %4i | sub r%i r%i r%i\n", self->num, args[ARG_1] + 1,
         args[ARG_2] + 1, args[ARG_3] + 1);
}

void operation_sub(t_carriage *self)
{
    //    need change "3" to constant later
    int     op_len;
    int     args[3];
    char    type_codes[3];
    int     sub;

    if (operation_precheck_args(self, args, type_codes, 3, &op_len) == SUCCESS
        && type_codes[ARG_1] == REG_CODE
        && type_codes[ARG_2] == REG_CODE
        && type_codes[ARG_3] == REG_CODE)
    {
print_op_log(self, args);

        sub = self->registers[args[ARG_1]] - self->registers[args[ARG_2]];
        if ((self->registers[args[ARG_3]] = sub) == 0)
            self->carry = TRUE;
        else
            self->carry = FALSE;
    }
    self->arena_position = (self->arena_position + op_len) % MEM_SIZE;
}