#include "operation.h"

static void                print_op_log(t_carriage *self, int arg, int position)
{
		if (vm_verbosity_lvl() & 4)
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
	t_op 		op;
    int         position;
    t_carriage  *new_carriage;
    t_list      *new_node;

    op = g_op[OP_LFORK - 1];
    op.op_len = OP_CODE_SIZE + op.t_dir_size;
    op.args[0] = arena_get_n_bytes_from(self->arena, self->arena_position + OP_CODE_SIZE, op.t_dir_size);
    position = self->arena_position + op.args[0];

print_op_log(self, op.args[0], position);

    new_carriage = carriage_new(self->p_name, self->arena, position, vm_num_of_carriages_and_increase());
    _fill_new_carriage(self, new_carriage);
//arena_set_last_live_player(new_carriage->arena, new_carriage->p_name);

	self->arena_position = (self->arena_position + op.op_len) % MEM_SIZE;
    if ((new_node = ft_lstnew((void *) new_carriage, sizeof(t_carriage))) == NULL)
        ft_raise(__FILE__, __LINE__, ENOMEMORY);
    vm_add_new_carriage_node(new_node);
}