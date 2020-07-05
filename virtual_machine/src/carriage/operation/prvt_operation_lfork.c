#include "prvt_operation.h"

static void                print_op_log(t_carriage *self, int arg, int position)
{
    printf("P %4i | lfork %i (%i)\n", self->num, arg, position);
}

static void            _fill_new_carriage(t_carriage *old, t_carriage *new)
{
    int         i;

    new->carry = old->carry;
    new->last_live_cycle = old->last_live_cycle;
    i = 0;
    while (i < 16)
    {
        new->registers[i] = old->registers[i];
        i++;
    }
}

void            operation_lfork(t_carriage *self)
{
    int         op_len;
    int         position;
    int         arg;
    t_carriage  *new_carriage;
    t_list      *new_node;

    op_len = ONE_BYTE + TWO_BYTES;
    arg = arena_get_n_bytes_from(self->arena, self->arena_position + ONE_BYTE, TWO_BYTES);
    position = self->arena_position + arg;

print_op_log(self, arg, position);

    new_carriage = carriage_new(self->player_name, self->arena, position, vm_num_of_carriages_and_increase());
    _fill_new_carriage(self, new_carriage);

    self->arena_position = (self->arena_position + op_len) % MEM_SIZE;
    if ((new_node = ft_lstnew((void *) new_carriage, sizeof(t_carriage))) == NULL)
        raise(__FILE__, __LINE__, ENOMEMORY);
    vm_add_new_carriage_node(new_node);
}