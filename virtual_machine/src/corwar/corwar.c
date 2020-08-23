/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corwar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 22:35:40 by yurezz            #+#    #+#             */
/*   Updated: 2020/08/23 14:05:34 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_corwar.h"
#include "prvt_vm.h"
#include "prvt_vm_params.h"

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
		ft_raise(__FILE__, __LINE__, EINVALCONSTANTS);
	}
	else if (argc < 2)
		ft_raise(__FILE__, __LINE__, EUSAGE);
	return ;
}

int				prvt_corewar_chose_regime(t_vm *this)
{
	if (this->params->ncurses == TRUE)
		return (VISUAL_MODE);
	return (DEFAULT_MODE);
}

int				main(int argc, char *argv[])
{
	t_vm				*this;
	static t_vm_play_fptr	vmptf[2] = {vm_play, vm_play_visual};

	prvt_corwar_precondition_check(argc);
	this = vm_singleton(VM_INSTANTIATE, argc - 1, argv + 1);
	vmptf[prvt_corewar_chose_regime(this)](this);
	(void)vm_singleton(VM_DESTRUCT, 0, NULL);
	return (SUCCESS);
}
