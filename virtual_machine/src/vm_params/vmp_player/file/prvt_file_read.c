/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_file_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:18:38 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/01 18:18:38 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_file.h"

void			prvt_file_read(tt_file *self)
{
	int			chunk;

	chunk = 0;
	prvt_file_allocate_intitial_value(self);
	self->total = 0;
	while ((chunk =
	read(self->fd, self->data + self->total, INITIAL_CHUNK)) > 0)
	{
		self->total += chunk;
		if (self->total == self->capacity)
			prvt_file_reallocate_value(self);
	}
	return ;
}
