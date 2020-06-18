#include "_operation.h"

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
    int     t_ind;

    argument_type_code =
            (char)arena_get_n_bytes_from(self->arena, self->arena_position + ONE_BYTE, ONE_BYTE);

    result = SUCCESS;
    *op_len = ONE_BYTE + ONE_BYTE;
    i = 0;
    while (i < num_of_args)
    {
        type_codes[i] = (argument_type_code >> (6 - 2 * i)) & TWO_BITS_MASK;
        if (type_codes[i] == CODE_T_REG)
        {
            args[i] = arena_get_n_bytes_from(self->arena, (self->arena_position + *op_len), ONE_BYTE) - 1;
            *op_len += ONE_BYTE;
            if (args[i] < 1 || args[i] > 16)
                result = FAILURE;
        }
        else if (type_codes[i] == CODE_T_DIR)
        {
            t_dir_size = t_dir_size_for_the_op(self->op_code);
            args[i] = arena_get_n_bytes_from(self->arena, self->arena_position + *op_len, t_dir_size);
            *op_len += t_dir_size;
        }
        else if (type_codes[i] == CODE_T_IND)
        {
            args[i] = arena_get_n_bytes_from(self->arena, self->arena_position + *op_len, TWO_BYTES);
//            t_ind = arena_get_n_bytes_from(self->arena, self->arena_position + op_len, TWO_BYTES) % IDX_MOD;
//            args[i] = arena_get_n_bytes_from(self->arena, self->arena_position + t_ind, FOUR_BYTES);
            *op_len += TWO_BYTES;
        }
        else
        {
            result = FAILURE;
            break;
        }
        i++;
    }
    return result;
}