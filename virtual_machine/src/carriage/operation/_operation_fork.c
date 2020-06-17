#include "_operation.h"

//don`t checked
static void            _fill_new_carriage(t_carriage *old, t_carriage *new)
{
    int         i;

    new->carry = old->carry;
//    new->op_code = old->op_code;
//    new->is_correct_op_code = old->is_correct_op_code;
//    new->cycles_to_perform_op = old->cycles_to_perform_op;
    new->last_live_cycle = old->last_live_cycle;
//    new->is_correct_op_code = old->is_correct_op_code;
    i = 0;
    while (i < 16)
    {
        new->registers[i] = old->registers[i];
        i++;
    }
}

void            _operation_fork(t_carriage *self)
{
    int         op_len;
    int         position;
    t_carriage  *new_carriage;
    t_vm        *vm;

    op_len = ONE_BYTE + TWO_BYTES;
    position = arena_get_n_bytes_from(self->arena, self->arena_position + ONE_BYTE, TWO_BYTES) % IDX_MOD;
    new_carriage = carriage_new(self->player_name, self->arena, position);
    _fill_new_carriage(self, new_carriage);

    vm = vm_singleton(VM_INSTANTIATE, 0, NULL);
    self->arena_position = op_len;
}