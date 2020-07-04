#include "prvt_operation.h"

static void                print_op_log(t_carriage *self, int *args)
{
    printf("P %4i | lld %i r%i\n", self->num, args[0], args[1] + 1);
}

//don`t checked
void                    prvt_operation_lld(t_carriage *self)
{
//    need change "2" to constant later
    int     op_len;
    int     args[2];
    char    type_codes[2];

    if (prvt_operation_precheck_args(self, args, type_codes, 2, &op_len) == SUCCESS
        && (type_codes[0] == CODE_T_IND || type_codes[0] == CODE_T_DIR)
        && type_codes[1] == CODE_T_REG)
    {
        if (type_codes[0] == CODE_T_IND)
            args[0] = arena_get_n_bytes_from(self->arena, self->arena_position + args[0], TWO_BYTES); // like original vm
//            args[0] = arena_get_n_bytes_from(self->arena, self->arena_position + args[0], FOUR_BYTES); // need to be

print_op_log(self, args);

        if ((self->registers[args[1]] = args[0]) == 0)
            self->carry = 1;
        else
            self->carry = 0;
    }
    if (op_len <= 0)
    {
        printf("SOMETHING WRONG WITH OP_LEN IN _OPERATION_LLD\n");
        exit(1);
    }
    self->arena_position = (self->arena_position + op_len) % MEM_SIZE;
}