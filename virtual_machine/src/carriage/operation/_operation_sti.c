#include "_operation.h"

//don`t checked
void            _operation_sti(t_carriage *self)
{
    //    need change "3" to constant later
    int     op_len;
    int     args[3];
    char    type_codes[3];
    int     position;

    if (_operation_precheck_args(self, args, type_codes, 3, &op_len) == SUCCESS
        && type_codes[0] == CODE_T_REG
        && (type_codes[1] == CODE_T_REG || type_codes[1] == CODE_T_DIR || type_codes[1] == CODE_T_IND)
        && (type_codes[2] == CODE_T_REG || type_codes[2] == CODE_T_DIR))
    {
        if (type_codes[1] == CODE_T_REG)
            args[1] = self->registers[args[1]];
        else if (type_codes[1] == CODE_T_IND) // don't shure
            args[1] = arena_get_n_bytes_from(self->arena, self->arena_position + args[1] % IDX_MOD, FOUR_BYTES);
//            args[1] = args[1]; check it, or ask someone else

        if (type_codes[2] == CODE_T_REG)
            args[2] = self->registers[args[2]];

        position = self->arena_position + (args[1] + args[2]) % IDX_MOD;
//        arena_print_dump(self->arena);
        arena_write_four_bytes_to_data(self->arena, position, self->registers[args[0]]);
//        write(1, "\n\n\n\n", 4);
//        arena_print_dump(self->arena);
    }
    if (op_len <= 0)
    {
        printf("SOMETHING WRONG WITH OP_LEN IN _OPERATION_STI\n");
        exit(1);
    }
    self->arena_position = (self->arena_position + op_len) % MEM_SIZE;
}