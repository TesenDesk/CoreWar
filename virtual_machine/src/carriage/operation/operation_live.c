/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_live.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 13:59:49 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/10 15:54:20 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

static void                print_op_log(t_carriage *self, int arg)
{
	if (vm_verbosity_lvl() & 4)
        printf("P %4i | live %i\n", self->num, arg);
}

void operation_live(t_carriage *self)
{
	t_op	op;
	int 	arg;

    op = g_op[OP_LIVE - 1];
    op.op_len = OP_CODE_SIZE + op.t_dir_size;
    op.args[0] = arena_get_n_bytes_from(self->arena, self->arena_position + OP_CODE_SIZE, op.t_dir_size);
	print_op_log(self, op.args[0]);
	arena_set_last_live_player(self->arena, op.args[0] * -1);
	self->last_live_cycle = vm_global_counter();
    vm_increase_num_of_live_ops();
    self->arena_position = (self->arena_position + op.op_len) % MEM_SIZE;
}
