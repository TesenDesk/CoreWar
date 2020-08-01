/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:55:24 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/01 12:55:35 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_visual.h"

void		process_keys(t_vm *self)
{
	int		c;

	c = getch();
	self->key = c;
	if (c == 65)
	{
		wattron(self->wins->info, COLOR_PAIR(B_INFO) | A_BOLD);
		self->speed += 1;
		if (self->speed > 10)
			self->speed = 10;
		wattroff(self->wins->info, COLOR_PAIR(B_INFO) | A_BOLD);
	}
	else if (c == 66)
	{
		wattron(self->wins->info, COLOR_PAIR(B_INFO) | A_BOLD);
		self->speed -= 1;
		if (self->speed < 1)
			self->speed = 1;
		wattroff(self->wins->info, COLOR_PAIR(B_INFO) | A_BOLD);
	}
	else if (c == 120)
		self->urgent_break = TRUE;
	getch();
}
