#include "prvt_operation.h"

static void                print_op_log(t_carriage *self, int *args)
{
    printf("P %4i | lld %i r%i\n", self->num, args[ARG_1], args[ARG_2] + 1);
}

void operation_lld(t_carriage *self)
{
//    need change "2" to constant later
    int     op_len;
    int     args[2];
    char    type_codes[2];

    if (operation_precheck_args(self, args, type_codes, 2, &op_len) == SUCCESS
        && (type_codes[ARG_1] == IND_CODE || type_codes[ARG_1] == DIR_CODE)
        && type_codes[ARG_2] == REG_CODE)
    {
        if (type_codes[ARG_1] == IND_CODE)
            args[ARG_1] = arena_get_n_bytes_from(self->arena, self->arena_position + args[ARG_1], TWO_BYTES); // like original vm
//            args[0] = arena_get_n_bytes_from(self->arena, self->arena_position + args[0], FOUR_BYTES); // need to be

		print_op_log(self, args);

        if ((self->registers[args[ARG_2]] = args[ARG_1]) == 0)
            self->carry = TRUE;
        else
            self->carry = FALSE;
    }
    self->arena_position = (self->arena_position + op_len) % MEM_SIZE;
}