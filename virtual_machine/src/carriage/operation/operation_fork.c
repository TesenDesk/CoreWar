/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:37:53 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/26 16:07:28 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

static void			print_op_log(t_carriage *self, int arg, int position)
{
	if (vm_verbosity_lvl() & 4)
		printf("P %4i | fork %i (%i)\n", self->num, arg, position);
}

static void			prvt_fill_new_carriage(t_carriage *old, t_carriage *new)
{
	int				i;

	new->carry = old->carry;
	new->last_live_cycle = old->last_live_cycle;
	i = 0;
	while (i < 16)
	{
		new->registers[i] = old->registers[i];
		i++;
	}
}

void				operation_fork(t_carriage *self)
{
	t_op		op;
	int			position;
	t_carriage	*new_carriage;
	t_list		*new_node;

	op = g_op[OP_FORK - 1];
	op.op_len = OP_CODE_SIZE + op.t_dir_size;
	op.args[0] = arena_get_n_bytes_from(self->arena,
	self->arena_position + OP_CODE_SIZE, op.t_dir_size);
	position = op.args[0] % IDX_MOD + self->arena_position;
	print_op_log(self, op.args[0], position);
	new_carriage = carriage_new(self->player_name, self->arena,
	position, vm_num_of_carriages_and_increase());
	prvt_fill_new_carriage(self, new_carriage);
	self->arena_position = (self->arena_position + op.op_len) % MEM_SIZE;
	if ((new_node = ft_lstnew((void *)new_carriage, sizeof(t_carriage)))
	== NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	vm_add_new_carriage_node(new_node);
}
