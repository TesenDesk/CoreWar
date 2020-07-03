#include "_operation.h"

static void                print_op_log(t_carriage *self, int *args, char *type_codes)
{
    if (type_codes[1] == CODE_T_REG)
        printf("P %4i | st r%i %i\n", self->num, args[0] + 1, args[1] + 1);
    else
        printf("P %4i | st r%i %i\n", self->num, args[0] + 1, args[1]);
}

void            _operation_st(t_carriage *self)
{
    //    need change "2" to constant later
    int     op_len;
    int     args[2];
    char    type_codes[2];

    if (_operation_precheck_args(self, args, type_codes, 2, &op_len) == SUCCESS
        && type_codes[0] == CODE_T_REG
        && (type_codes[1] == CODE_T_REG || type_codes[1] == CODE_T_IND))
    {

print_op_log(self, args, type_codes);

        if (type_codes[1] == CODE_T_IND)
            arena_write_four_bytes_to_data(self->arena, self->arena_position + args[1] % IDX_MOD, self->registers[args[0]]);
        else
            self->registers[args[1]] = self->registers[args[0]]; // - 1 need for indexing
    }
    if (op_len <= 0)
    {
        printf("SOMETHING WRONG WITH OP_LEN IN _OPERATION_ST\n");
        exit(1);
    }
    self->arena_position = (self->arena_position + op_len) % MEM_SIZE;
}