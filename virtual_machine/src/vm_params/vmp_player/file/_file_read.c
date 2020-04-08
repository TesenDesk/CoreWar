/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _file_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 21:42:24 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 21:45:49 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_file.h"

static void			_file_allocate_intitial_value(t_file *self)
{
	if ((self->data = ft_memalloc(INITIAL_CHUNK * sizeof(char))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	return;
}

static void			_file_get_chunk(t_file *self)
{
	ssize_t			chunk;

	if ((chunk = read(self->fd, self->data, INITIAL_CHUNK)) == NULL)
		raise(__FILE__, __LINE__, ECANNOTREAD);
	self->total += chunk;
	if (chunk == 0)
		self->is_read = TRUE;
	return;
}

static void			_file_reallocate_value(t_file *self)
{
	ssize_t			new_capacity;

	new_capacity = 2 * self->capacity;
	if (new_capacity > INT_MAX)
		raise(__FILE__, __LINE__, ENOMEMORY);
	if (ft_realloc_safe(&self->data, self->capacity, new_capacity) == FAILURE)
		raise(__FILE__, __LINE__, ENOMEMORY);
	self->capacity = new_capacity;
	return;
}

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
