/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _operation_live.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 13:59:49 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/10 15:54:20 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_operation.h"

static void                print_op_log(t_carriage *self, int arg)
{
    printf("P %4i | live %i\n", self->num, arg);
}

void                    _operation_live(t_carriage *self)
{
    int position;
    int op_len;
    int arg;

    position = self->arena_position;
    op_len = ONE_BYTE + FOUR_BYTES; // 5 bytes for op live
    arg = arena_get_n_bytes_from(self->arena, position + ONE_BYTE, FOUR_BYTES);
    if ((arg * -1) == self->player_name)
    {
        arena_set_last_live_player(self->arena, self->player_name);
    }
    self->last_live_cycle = vm_global_counter();
    vm_increase_num_of_live_ops(); // не нашел, нужно ли увеличивать счетчик лайвов, если для каретку лайв не успешный

print_op_log(self, arg);


    self->arena_position = (self->arena_position + op_len) % MEM_SIZE;
}




//void					_operation_convert_ind_to_dir(int *arg)
//{
//	*arg %= IDX_MOD;
//	return;
//}
//
//void					_operation_mock(t_carriage *carriage, int args[NB_ARGS])
//{
//	return;
//}
//
//void					_operation_live(t_carriage *carriage, int args[NB_ARGS])
//{
//	carriage_set_live(carriage);
//	if (args[ARG_1] + carriage_player_name(carriage) == 0)
//		carriage_set_player_is_alive(carriage);
//	return;
//}
//
//void					_operation_ld(t_carriage *carriage, int args[NB_ARGS])
//{
//	long				value;
//
//	value = _operation_ind
//	return;
//}
//void					_operation_st(t_carriage *carriage, int args[NB_ARGS])
//{
//	return;
//}
//
//void					_operation_add(t_carriage *carriage, int args[NB_ARGS])
//{
//	return;
//}
//
//void					_operation_sub(t_carriage *carriage, int args[NB_ARGS])
//{
//	return;
//}
//
//void					_operation_and(t_carriage *carriage, int args[NB_ARGS])
//{
//	return;
//}
//
//void					_operation_or(t_carriage *carriage, int args[NB_ARGS])
//{
//	return;
//}
//
//void					_operation_xor(t_carriage *carriage, int args[NB_ARGS])
//{
//	return;
//}
//
//void					_operation_zjmp(t_carriage *carriage, int args[NB_ARGS])
//{
//	return;
//}
//
//void					_operation_ldi(t_carriage *carriage, int args[NB_ARGS])
//{
//	return;
//}
//
//void					_operation_sti(t_carriage *carriage, int args[NB_ARGS])
//{
//	return;
//}
//
//void					_operation_fork(t_carriage *carriage, int args[NB_ARGS])
//{
//	return;
//}
//
//void					_operation_lld(t_carriage *carriage, int args[NB_ARGS])
//{
//	return;
//}
//
//void					_operation_lldi(t_carriage *carriage, int args[NB_ARGS])
//{
//	return;
//}
//
//void					_operation_lfork(t_carriage *carriage, int args[NB_ARGS])
//{
//	return;
//}
//
//void					_operation_aff(t_carriage *carriage, int args[NB_ARGS])
//{
//	return;
//}
//
