/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:55:24 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/30 16:20:13 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_visual.h"

void		process_keys(t_vm *vm)
{
	int		c;

	c = getch();
	vm_set_key(vm, c);
	if (c == 65)
	{
		wattron(vm_get_wins(vm)->info, COLOR_PAIR(B_INFO) | A_BOLD);
		vm_set_speed(vm, vm_get_speed(vm) + 1);
		if (vm_get_speed(vm) > 100)
			vm_set_speed(vm, 100);
		wattroff(vm_get_wins(vm)->info, COLOR_PAIR(B_INFO) | A_BOLD);
	}
	else if (c == 66)
	{
		wattron(vm_get_wins(vm)->info, COLOR_PAIR(B_INFO) | A_BOLD);
		vm_set_speed(vm, vm_get_speed(vm) - 1);
		if (vm_get_speed(vm) < 1)
			vm_set_speed(vm, 1);
		wattroff(vm_get_wins(vm)->info, COLOR_PAIR(B_INFO) | A_BOLD);
	}
	else if (c == 120)
		vm_set_urgent_break(vm, TRUE);
	getch();
}
