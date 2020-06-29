#include "_operation.h"

static int                     is_arg_type_valid(char arg_type_code, int num_of_arg, int op_code)
{
    char     args_codes[16][3][3] = {
            {{CODE_T_DIR, 0, 0}, {0, 0, 0}, {0, 0, 0}}, //live
            {{CODE_T_DIR, CODE_T_IND, 0}, {CODE_T_REG, 0, 0}, {0, 0, 0}}, //ld
            {{CODE_T_REG, 0, 0}, {CODE_T_REG, CODE_T_IND, 0}, {0, 0, 0}}, //st
            {{CODE_T_REG, 0, 0}, {CODE_T_REG, 0, 0}, {CODE_T_REG, 0, 0}}, //add
            {{CODE_T_REG, 0, 0}, {CODE_T_REG, 0, 0}, {CODE_T_REG, 0, 0}}, //sub
            {{CODE_T_REG, CODE_T_DIR, CODE_T_IND}, {CODE_T_REG, CODE_T_DIR, CODE_T_IND}, {CODE_T_REG, 0, 0}}, //and
            {{CODE_T_REG, CODE_T_DIR, CODE_T_IND}, {CODE_T_REG, CODE_T_DIR, CODE_T_IND}, {CODE_T_REG, 0, 0}}, //or
            {{CODE_T_REG, CODE_T_DIR, CODE_T_IND}, {CODE_T_REG, CODE_T_DIR, CODE_T_IND}, {CODE_T_REG, 0, 0}}, //xor
            {{CODE_T_DIR, 0, 0}, {0, 0, 0}, {0, 0, 0}}, //zjmp
            {{CODE_T_REG, CODE_T_DIR, CODE_T_IND}, {CODE_T_REG, CODE_T_DIR, 0}, {CODE_T_REG, 0, 0}}, //ldi
            {{CODE_T_REG, 0, 0}, {CODE_T_REG, CODE_T_DIR, CODE_T_IND}, {CODE_T_REG, CODE_T_DIR, 0}}, //sti
            {{CODE_T_DIR, 0, 0}, {0, 0, 0}, {0, 0, 0}}, //fork
            {{CODE_T_DIR, CODE_T_IND, 0}, {CODE_T_REG, 0, 0}, {0, 0, 0}}, //lld
            {{CODE_T_REG, CODE_T_DIR, CODE_T_IND}, {CODE_T_REG, CODE_T_DIR, 0}, {CODE_T_REG, 0, 0}}, //lldi
            {{CODE_T_DIR, 0, 0}, {0, 0, 0}, {0, 0, 0}}, //lfork
            {{CODE_T_REG, 0, 0}, {0, 0, 0}, {0, 0, 0}}, //aff
    };
    int     i = 0;

    while (i < 3)
    {
        if (args_codes[op_code - 1][num_of_arg][i] == arg_type_code)
            return TRUE;
        i++;
    }
    return FALSE;
}

static int                 t_dir_size_for_the_op(int op_code)
{
    int     t_dir_sizes[NUMBER_OF_OPERATIONS] = {0, 4, 4, 4, 4, 4, 4, 4,
                                                 4, 2, 2, 2, 2, 4, 2, 2, 4};
    return t_dir_sizes[op_code];
}

// fill args[num_of_args], type_codes[num_of_args] and op_len
// return SUCCESS all args_codes is real and if arg_code == CODE_T_REG and t_reg_arg >= 1 and t_reg_arg <= 16
// else return FAILURE
int                    _operation_precheck_args(t_carriage *self, int *args, char *type_codes, int num_of_args, int *op_len)
{
    char    argument_type_code;
    int     i;
    int     result;
    int     t_dir_size;

    argument_type_code =
            (char)arena_get_n_bytes_from(self->arena, self->arena_position + ONE_BYTE, ONE_BYTE);

    result = SUCCESS;
    *op_len = ONE_BYTE + ONE_BYTE;
    t_dir_size = t_dir_size_for_the_op(self->op_code);
    i = 0;
    while (i < num_of_args)
    {
        type_codes[i] = (argument_type_code >> (6 - 2 * i)) & TWO_BITS_MASK;
//        if (is_arg_type_valid(type_codes[i], i, self->op_code) == FALSE)
//        {
//            return FAILURE;
//        }
        if (type_codes[i] == CODE_T_REG)
        {
            args[i] = arena_get_n_bytes_from(self->arena, (self->arena_position + *op_len), ONE_BYTE) - 1;
            *op_len += ONE_BYTE;
            if (args[i] < 0 || args[i] >= 16)
            {
                result = FAILURE;
//                break;
            }
        }
        else if (type_codes[i] == CODE_T_DIR)
        {
            args[i] = arena_get_n_bytes_from(self->arena, self->arena_position + *op_len, t_dir_size);
            *op_len += t_dir_size;
        }
        else if (type_codes[i] == CODE_T_IND)
        {
            args[i] = arena_get_n_bytes_from(self->arena, self->arena_position + *op_len, TWO_BYTES);
            *op_len += TWO_BYTES;
        }
        else
        {
//            return FAILURE;
            result = FAILURE;
            args[i] = 0;
//            break;
        }
        i++;
    }
    return result;
}