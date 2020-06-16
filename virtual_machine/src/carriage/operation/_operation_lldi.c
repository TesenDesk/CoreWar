#include "_operation.h"

//don`t checked
void            _operation_lldi(t_carriage *self)
{
    //    need change "3" to constant later
    int     op_len;
    int     args[3];
    char    type_codes[3];

    if (_operation_precheck_args(self, args, type_codes, 3, &op_len) == SUCCESS
        && (type_codes[0] == CODE_T_REG || type_codes[0] == CODE_T_DIR || type_codes[0] == CODE_T_IND)
        && (type_codes[1] == CODE_T_REG || type_codes[1] == CODE_T_DIR)
        && type_codes[2] == CODE_T_REG)
    {
        if (type_codes[0] == CODE_T_REG)
            args[0] = self->registers[args[0]];
        else if (type_codes[0] == CODE_T_IND)
            args[0] = arena_get_n_bytes_from(self->arena, self->arena_position + args[0] % IDX_MOD, FOUR_BYTES);

        if (type_codes[1] == CODE_T_REG)
            args[1] = self->registers[args[1]];

        self->registers[args[2]] = self->arena_position + (args[0] + args[1]);
    }
    if (op_len <= 0)
    {
        printf("SOMETHING WRONG WITH OP_LEN IN _OPERATION_LDI\n");
        exit(1);
    }
    self->arena_position = (self->arena_position + op_len) % MEM_SIZE;
}