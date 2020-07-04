#include "prvt_operation.h"

static void                print_op_log(t_carriage *self, int *args)
{
    printf("P %4i | ldi %i %i r%i\n", self->num, args[0], args[1], args[2] + 1);
    printf("       | -> load from %i + %i = %i (with pc and mod %i)\n",
            args[0], args[1], args[0] + args[1], self->arena_position + (args[0] + args[1]) % IDX_MOD);
}

void            prvt_operation_ldi(t_carriage *self)
{
    //    need change "3" to constant later
    int     op_len;
    int     args[3];
    char    type_codes[3];

    if (prvt_operation_precheck_args(self, args, type_codes, 3, &op_len) == SUCCESS
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

print_op_log(self, args);

        self->registers[args[2]] = arena_get_n_bytes_from(self->arena, self->arena_position + (args[0] + args[1]) % IDX_MOD, FOUR_BYTES);

    }
    if (op_len <= 0)
    {
        printf("SOMETHING WRONG WITH OP_LEN IN _OPERATION_LDI\n");
        exit(1);
    }
    self->arena_position = (self->arena_position + op_len) % MEM_SIZE;
}