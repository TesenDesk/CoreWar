/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _file_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 21:42:24 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 23:02:24 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_file.h"

void			_file_read(t_file *self)
{
	_file_allocate_intitial_value(self);
	_file_get_chunk(self);
	while (self->is_read == FALSE)
	{
		if (self->total + INITIAL_CHUNK > self->capacity)
			_file_reallocate_value(self);
		_file_get_chunk(self);
	}
	return;
}
