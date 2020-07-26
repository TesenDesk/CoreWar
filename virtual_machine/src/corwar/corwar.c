/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corwar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 22:35:40 by yurezz            #+#    #+#             */
/*   Updated: 2020/07/26 16:07:28 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_corwar.h"

static void		prvt_corwar_precondition_check(int argc)
{
	if ((REG_SIZE < sizeof(char) || sizeof(int) < REG_SIZE) ||
		IND_SIZE < sizeof(char) ||
		MAX_ARGS_NUMBER < 4 ||
		MAX_PLAYERS < 1 ||
		REG_NUMBER < 1 ||
		IDX_MOD < 1 ||
		DIR_SIZE != REG_SIZE ||
		CYCLE_DELTA < 1 ||
		MAX_CHECKS < 1 ||
		NBR_LIVE < 0)
	{
		raise(__FILE__, __LINE__, EINVALCONSTANTS);
	}
	else if (argc < 2)
		raise(__FILE__, __LINE__, EUSAGE);
	return ;
}

int				main(int argc, char *argv[])
{
	t_vm		*this;

	prvt_corwar_precondition_check(argc);
	this = vm_singleton(VM_INSTANTIATE, argc - 1, argv + 1);
	vm_play(this);
	(void)vm_singleton(VM_DESTRUCT, 0, NULL);
	return (SUCCESS);
}
