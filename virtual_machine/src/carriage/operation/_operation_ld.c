#include "_operation.h"


void                    _operation_ld(t_carriage *self)
{
//    need change "2" to constant later
    int     op_len;
    int     args[2];
    char    type_codes[2];

    if (precheck_args(self, args, type_codes, 2, &op_len) == SUCCESS)
    {
//        if ((self->registers[args[1]] = args[0]) == 0)
        if ((self->registers[args[ARG_2]] = args[ARG_1]) == 0)
            self->carry = 1;
        else
            self->carry = 0;
    }
    else
        self->arena_position = (self->arena_position + op_len) % MEM_SIZE;


//    char     argument_type_code;
//    int      t_ind;
//    int      first_arg;
//    int      second_arg;
//    int      op_len;
//
//    op_len = ONE_BYTE;
//    argument_type_code =
//            (char) arena_get_n_bytes_from(self->arena, self->arena_position + op_len, ONE_BYTE);
//    if (argument_type_code >> 6 == CODE_T_DIR)
//    {
//        first_arg =
//                arena_get_n_bytes_from(self->arena, self->arena_position + op_len, FOUR_BYTES);
//        op_len += FOUR_BYTES;
//    }
//    else if (argument_type_code >> 6 == CODE_T_IND)
//    {
//        t_ind =
//                arena_get_n_bytes_from(self->arena, self->arena_position + op_len, TWO_BYTES) % IDX_MOD;
//        first_arg =
//                arena_get_n_bytes_from(self->arena, self->arena_position + t_ind, FOUR_BYTES);
//        op_len += TWO_BYTES;
//    }
//    else
//    {
//        self->arena_position += op_len;
//        return;
//    }
//
//    if ((argument_type_code >> 4 & TWO_BITS_MASK) == CODE_T_REG)
//    {
//        second_arg =
//                arena_get_n_bytes_from(self->arena, self->arena_position + op_len, ONE_BYTE);
//        op_len += ONE_BYTE;
////        check register valid!!! dont know what to do when register isn`t valid
//    }
//    else
//    {
//        self->arena_position += op_len;
//        return;
//    }
//
//
////    perform operation ld
//    if ((self->registers[second_arg] = first_arg) == 0)
//        self->carry = 1;
//    else
//        self->carry = 0;
//    self->arena_position += op_len;
}