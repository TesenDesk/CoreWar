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

// TODO: номер цикла где-то нужно учитывать

t_operation				*operation_dispatched(int state)
{
	static t_operation	operations[NUMBER_OF_OPERATIONS] =
	{
		_operation_mock,
		_operation_live,
		_operation_ld,
		_operation_st,
		_operation_add,
		_operation_sub,
		_operation_and,
		_operation_or,
		_operation_xor,
		_operation_zjmp,
		_operation_ldi,
		_operation_sti,
		_operation_fork,
		_operation_lld,
		_operation_lldi,
		_operation_lfork,
		_operation_aff,
	};

	return (operations[state]);
}

enum					e_arguments
{
	ARG_1,
	ARG_2,
	ARG_3,
	NB_ARGS,
};

void					_operation_convert_ind_to_dir(int *arg)
{
	*arg %= IDX_MOD;
	return;
}

void					_operation_mock(t_carriage *carriage, int args[NB_ARGS])
{
	return;
}

void					_operation_live(t_carriage *carriage, int args[NB_ARGS])
{
	carriage_set_live(carriage);
	if (args[ARG_1] + carriage_player_name(carriage) == 0)
		carriage_set_player_is_alive(carriage);
	return;
}

void					_operation_ld(t_carriage *carriage, int args[NB_ARGS])
{
	long				value;

	value = _operation_ind
	return;
}
void					_operation_st(t_carriage *carriage, int args[NB_ARGS])
{
	return;
}

void					_operation_add(t_carriage *carriage, int args[NB_ARGS])
{
	return;
}

void					_operation_sub(t_carriage *carriage, int args[NB_ARGS])
{
	return;
}

void					_operation_and(t_carriage *carriage, int args[NB_ARGS])
{
	return;
}

void					_operation_or(t_carriage *carriage, int args[NB_ARGS])
{
	return;
}

void					_operation_xor(t_carriage *carriage, int args[NB_ARGS])
{
	return;
}

void					_operation_zjmp(t_carriage *carriage, int args[NB_ARGS])
{
	return;
}

void					_operation_ldi(t_carriage *carriage, int args[NB_ARGS])
{
	return;
}

void					_operation_sti(t_carriage *carriage, int args[NB_ARGS])
{
	return;
}

void					_operation_fork(t_carriage *carriage, int args[NB_ARGS])
{
	return;
}

void					_operation_lld(t_carriage *carriage, int args[NB_ARGS])
{
	return;
}

void					_operation_lldi(t_carriage *carriage, int args[NB_ARGS])
{
	return;
}

void					_operation_lfork(t_carriage *carriage, int args[NB_ARGS])
{
	return;
}

void					_operation_aff(t_carriage *carriage, int args[NB_ARGS])
{
	return;
}
