/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _file_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 21:42:24 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/21 21:11:11 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_file.h"

void			_file_read(tt_file *self)
{
	int 		chunk;

	chunk = 0;
	_file_allocate_intitial_value(self);
	while ((chunk = read(self->fd, self->data + self->total, INITIAL_CHUNK)) > 0)
	{
		self->total += chunk;
		if (self->total == self->capacity)
			_file_reallocate_value(self);
	}
	return;
}
