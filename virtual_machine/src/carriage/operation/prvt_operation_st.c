#include "prvt_operation.h"

static void                print_op_log(t_carriage *self, int *args, char *type_codes)
{
    if (type_codes[1] == REG_CODE)
        printf("P %4i | st r%i %i\n", self->num, args[ARG_1] + 1,
             args[ARG_2] + 1);
    else
        printf("P %4i | st r%i %i\n", self->num, args[ARG_1] + 1, args[ARG_2]);
}

void operation_st(t_carriage *self)
{
    //    need change "2" to constant later
    int     op_len;
    int     args[2];
    char    type_codes[2];

    if (operation_precheck_args(self, args, type_codes, 2, &op_len) == SUCCESS
        && type_codes[ARG_1] == REG_CODE
        && (type_codes[ARG_2] == REG_CODE || type_codes[ARG_2] == IND_CODE))
    {

print_op_log(self, args, type_codes);

        if (type_codes[ARG_2] == IND_CODE)
            arena_write_four_bytes_to_data(self->arena, self->arena_position
                                                          + args[ARG_2] %
                                                                IDX_MOD,
                                         self->registers[args[ARG_1]]);
        else
            self->registers[args[ARG_2]] = self->registers[args[ARG_1]];
    }
    self->arena_position = (self->arena_position + op_len) % MEM_SIZE;
}