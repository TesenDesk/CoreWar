/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corwar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 22:35:40 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/09 23:23:57 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_corwar.h"

// TODO: Добавить проверку REG_SIZE. Видио  в классе corwar.
static void		_corwar_precondition_check()
{
	if (REG_SIZE < sizeof(char) || sizeof(long) < REG_SIZE)
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