/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corwar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 22:35:40 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/10 15:53:04 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_corwar.h"

// TODO: Добавить проверку REG_SIZE. Видио  в классе corwar.
static void		_corwar_precondition_check()
{
	if (
		(REG_SIZE < sizeof(char) || sizeof(int) < REG_SIZE) ||
		IND_SIZE < sizeof(char) ||

		MAX_ARGS_NUMBER < 4 ||
		MAX_PLAYERS < 1 ||
		REG_NUMBER < 1 ||

		IDX_MOD < 1 ||
		DIR_SIZE != REG_SIZE ||
		CYCLE_DELTA < 1 ||
		MAX_CHECKS < 1 ||

		NBR_LIVE < 0

		)
		raise(__FILE__, __LINE__, EINVALCONSTANTS);
	return;
}

int				main(int argc, char *argv[])
{
	t_vm		*this;

	_corwar_precondition_check();
	this = vm_singletone(VM_INSTANTIATE, argc, argv);
	vm_play(this);
	(void)vm_singletone(VM_DESTRUCT, 0, NULL);
	return (SUCCESS);
}