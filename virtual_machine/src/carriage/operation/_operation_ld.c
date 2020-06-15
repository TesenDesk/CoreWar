#include "_operation.h"

int                 t_dir_size_for_the_op(int op_code)
{
    int     t_dir_sizes[NUMBER_OF_OPERATIONS] = {0, 4, 4, 4, 4, 4, 4, 4,
                                       4, 2, 2, 2, 2, 4, 2, 2, 4};
    return t_dir_sizes[op_code];
}

// fill args, type_codes and op_len
// return SUCCESS all args_codes is real
// else return FAILURE
int                    precheck_args(t_carriage *self, int *args, char *type_codes, int num_of_args, int *op_len) {
    char    argument_type_code;
    int     i;
    int     result;
    int     t_dir_size;
    int     t_ind;

    argument_type_code = (char) arena_get_n_bytes_from(self->arena, self->arena_position + ONE_BYTE, ONE_BYTE);

    result = SUCCESS;
    *op_len = ONE_BYTE + ONE_BYTE;
    i = 0;
    while (i < num_of_args)
    {
        type_codes[i] = (argument_type_code >> (6 - i)) & TWO_BITS_MASK;
        if (type_codes[i] == CODE_T_REG)
        {
            args[i] = arena_get_n_bytes_from(self->arena, self->arena_position + op_len, ONE_BYTE);
            *op_len += ONE_BYTE;
            if (args[i] >= 1 && args[i] <= 16)
                result = FAILURE;
        }
        else if (type_codes[i] == CODE_T_DIR)
        {
            t_dir_size = t_dir_size_for_the_op(self->op_code);
            args[i] = arena_get_n_bytes_from(self->arena, self->arena_position + op_len, t_dir_size);
            *op_len += t_dir_size;
        }
        else if (type_codes[i] == CODE_T_IND)
        {
            t_ind = arena_get_n_bytes_from(self->arena, self->arena_position + op_len, TWO_BYTES) % IDX_MOD;
            args[i] = arena_get_n_bytes_from(self->arena, self->arena_position + t_ind, FOUR_BYTES);
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

void                    _operation_ld(t_carriage *self)
{
    char     argument_type_code;
    int      t_ind;
    int      first_arg;
    int      second_arg;
    int      op_len;

    op_len = ONE_BYTE;
    argument_type_code =
            (char) arena_get_n_bytes_from(self->arena, self->arena_position + op_len, ONE_BYTE);
    if (argument_type_code >> 6 == CODE_T_DIR)
    {
        first_arg =
                arena_get_n_bytes_from(self->arena, self->arena_position + op_len, FOUR_BYTES);
        op_len += FOUR_BYTES;
    }
    else if (argument_type_code >> 6 == CODE_T_IND)
    {
        t_ind =
                arena_get_n_bytes_from(self->arena, self->arena_position + op_len, TWO_BYTES) % IDX_MOD;
        first_arg =
                arena_get_n_bytes_from(self->arena, self->arena_position + t_ind, FOUR_BYTES);
        op_len += TWO_BYTES;
    }
    else
    {
        self->arena_position += op_len;
        return;
    }

    if ((argument_type_code >> 4 & TWO_BITS_MASK) == CODE_T_REG)
    {
        second_arg =
                arena_get_n_bytes_from(self->arena, self->arena_position + op_len, ONE_BYTE);
        op_len += ONE_BYTE;
//        check register valid!!! dont know what to do when register isn`t valid
    }
    else
    {
        self->arena_position += op_len;
        return;
    }


//    perform operation ld
    if ((self->registers[second_arg] = first_arg) == 0)
        self->carry = 1;
    else
        self->carry = 0;
    self->arena_position += op_len;
}