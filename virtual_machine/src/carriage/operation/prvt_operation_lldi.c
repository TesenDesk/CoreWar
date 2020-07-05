#include "prvt_operation.h"

static void                print_op_log(t_carriage *self, int *args)
{
    printf("P %4i | lldi %i %i r%i\n", self->num, args[ARG_1], args[ARG_2],
    		args[ARG_3] +
    1);
    printf("       | -> load from %i + %i = %i (with pc %i)\n",
           args[ARG_1], args[ARG_2], args[ARG_1] + args[ARG_2],
           self->arena_position +
           args[ARG_1] + args[ARG_2]);
}

void operation_lldi(t_carriage *self)
{
    //    need change "3" to constant later
    int     op_len;
    int     args[3];
    char    type_codes[3];
    int     arg;

    if (operation_precheck_args(self, args, type_codes, 3, &op_len) == SUCCESS
        && (type_codes[ARG_1] == REG_CODE || type_codes[ARG_1] == DIR_CODE ||
        type_codes[ARG_1] == IND_CODE)
        && (type_codes[ARG_2] == REG_CODE || type_codes[ARG_2] == DIR_CODE)
        && type_codes[ARG_3] == REG_CODE)
    {
        if (type_codes[ARG_1] == REG_CODE)
            args[ARG_1] = self->registers[args[ARG_1]];
        else if (type_codes[ARG_1] == IND_CODE)
            args[ARG_1] = arena_get_n_bytes_from(self->arena, self->arena_position + args[ARG_1] % IDX_MOD, FOUR_BYTES);
        if (type_codes[1] == REG_CODE)
            args[ARG_1] = self->registers[args[ARG_1]];

print_op_log(self, args);

        arg = arena_get_n_bytes_from(self->arena, self->arena_position +
        (args[ARG_1] + args[ARG_2]), FOUR_BYTES);

        if ((self->registers[args[ARG_3]] = arg) == 0)
            self->carry = TRUE;
        else
            self->carry = FALSE;
    }
    self->arena_position = (self->arena_position + op_len) % MEM_SIZE;
}