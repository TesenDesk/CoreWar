/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corwar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 22:35:40 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/03 23:16:37 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corwar.h"

int				main(int argc, char *argv[])
{
	t_vm		*this;

	this = vm_singletone(VM_INSTANTIATE, argc, argv);
	vm_play(this);
	(void)vm_singletone(VM_DESTRUCT, 0, NULL);
	return (SUCCESS);
}