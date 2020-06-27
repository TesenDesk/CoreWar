#include "_operation.h"

static void                print_op_log(t_carriage *self, int *args)
{
    printf("P%5i | or %i %i r%i\n", self->num, args[0], args[1], args[2] + 1);
}

void            _operation_or(t_carriage *self)
{
    //    need change "3" to constant later
    int     op_len;
    int     args[3];
    char    type_codes[3];
    int     sub;

    if (_operation_precheck_args(self, args, type_codes, 3, &op_len) == SUCCESS
        && (type_codes[0] == CODE_T_REG || type_codes[0] == CODE_T_DIR || type_codes[0] == CODE_T_IND)
        && (type_codes[1] == CODE_T_REG || type_codes[1] == CODE_T_DIR || type_codes[1] == CODE_T_IND)
        && type_codes[2] == CODE_T_REG)
    {
        if (type_codes[0] == CODE_T_REG)
            args[0] = self->registers[args[0]];
        else if (type_codes[0] == CODE_T_IND)
            args[0] = arena_get_n_bytes_from(self->arena, self->arena_position + args[0] % IDX_MOD, FOUR_BYTES);

        if (type_codes[1] == CODE_T_REG)
            args[1] = self->registers[args[1]];
        else if (type_codes[1] == CODE_T_IND)
            args[1] = arena_get_n_bytes_from(self->arena, self->arena_position + args[1] % IDX_MOD, FOUR_BYTES);

print_op_log(self, args);
        if ((self->registers[args[2]] = args[0] | args[1]) == 0)
            self->carry = 1;
        else
            self->carry = 0;
    }
    if (op_len <= 0)
    {
        printf("SOMETHING WRONG WITH OP_LEN IN _OPERATION_OR\n");
        exit(1);
    }
    self->arena_position = (self->arena_position + op_len) % MEM_SIZE;
}