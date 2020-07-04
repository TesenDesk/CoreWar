#include "prvt_operation.h"

static void                print_op_log(t_carriage *self, int *args)
{
    printf("P %4i | ld %i r%i\n", self->num, args[0], args[1] + 1);
}

void                    prvt_operation_ld(t_carriage *self)
{
//    need change "2" to constant later
    int     num_of_args = prvt_op_num_of_args(self->op_code);
    int     op_len;
    int     args[num_of_args];
    char    type_codes[num_of_args];


    if (prvt_operation_precheck_args(self, args, type_codes, num_of_args, &op_len) == SUCCESS
        && (type_codes[0] == CODE_T_IND || type_codes[0] == CODE_T_DIR)
        && type_codes[1] == CODE_T_REG)
    {
//        especially need check this part with conversion t_ind to t_dir
        if (type_codes[0] == CODE_T_IND)
            args[0] = arena_get_n_bytes_from(self->arena, self->arena_position + args[0] % IDX_MOD, FOUR_BYTES);

print_op_log(self, args);

        if ((self->registers[args[1]] = args[0]) == 0)
            self->carry = 1;
        else
            self->carry = 0;
    }
    if (op_len <= 0)
    {
        printf("SOMETHING WRONG WITH OP_LEN IN _OPERATION_LD\n");
        exit(1);
    }
    self->arena_position = (self->arena_position + op_len) % MEM_SIZE;

}