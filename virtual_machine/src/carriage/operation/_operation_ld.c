#include "_operation.h"

//don`t checked
void                    _operation_ld(t_carriage *self)
{
//    need change "2" to constant later
    int     op_len;
    int     args[2];
    char    type_codes[2];

    if (_operation_precheck_args(self, args, type_codes, 2, &op_len) == SUCCESS
        && (type_codes[0] == CODE_T_IND || type_codes[0] == CODE_T_DIR)
        && type_codes[1] == CODE_T_REG)
    {
//        especially need check this part with conversion t_ind to t_dir
        if (type_codes[0] == CODE_T_IND)
            args[0] = arena_get_n_bytes_from(self->arena, self->arena_position + args[0] % IDX_MOD, FOUR_BYTES);

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