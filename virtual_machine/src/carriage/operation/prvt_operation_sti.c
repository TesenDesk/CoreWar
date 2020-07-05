#include "prvt_operation.h"

static void                print_op_log(t_carriage *self, int *args)
{
    printf("P %4i | sti r%i %i %i\n", self->num, args[0] + 1, args[ARG_2],
         args[ARG_3]);
    printf("       | -> store to %i + %i = %i (with pc and mod %i)\n",
           args[ARG_2], args[ARG_3], args[ARG_2] + args[ARG_3],
           self->arena_position + (args[ARG_2] + args[ARG_3]) % IDX_MOD);
}

//don`t checked
void operation_sti(t_carriage *self)
{
    //    need change "3" to constant later
    int     op_len;
    int     args[3];
    char    type_codes[3];
    int     position;

    if (operation_precheck_args(self, args, type_codes, 3, &op_len) == SUCCESS
        && type_codes[ARG_1] == REG_CODE
        && (type_codes[ARG_2] == REG_CODE || type_codes[ARG_2] == DIR_CODE ||
            type_codes[ARG_2] == IND_CODE)
        && (type_codes[ARG_3] == REG_CODE || type_codes[ARG_3] == DIR_CODE))
    {
        if (type_codes[ARG_2] == REG_CODE)
            args[ARG_2] = self->registers[args[ARG_2]];
        else if (type_codes[1] == IND_CODE)
            args[ARG_2] = arena_get_n_bytes_from(self->arena,
                                           self->arena_position + args[ARG_2] %
                                                                          IDX_MOD, FOUR_BYTES);
        if (type_codes[ARG_3] == REG_CODE)
            args[ARG_3] = self->registers[args[ARG_3]];

print_op_log(self, args);

        position = self->arena_position + (args[ARG_2] + args[ARG_3]) % IDX_MOD;
        arena_write_four_bytes_to_data(self->arena, position,
                                       self->registers[args[ARG_1]]);
    }
    self->arena_position = (self->arena_position + op_len) % MEM_SIZE;
}
