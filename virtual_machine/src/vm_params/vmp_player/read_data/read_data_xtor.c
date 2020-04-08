/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data_xtor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:28:46 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 19:58:53 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_read_data.h"

static void			_read_data_get_chunk(t_read_data *self, int fd)
{
	ssize_t			chunk;

	if ((chunk = read(fd, self->data, INITIAL_CHUNK)) == NULL)
		raise(__FILE__, __LINE__, ECANNOTREAD);
	self->total += chunk;
	if (chunk == 0)
		self->is_read = TRUE;
	return;
}

static void			_read_data_reallocate_value(t_read_data *self)
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

static void			_read_data_allocate_intitial_value(t_read_data *self)
{
	if ((self->data = ft_memalloc(INITIAL_CHUNK * sizeof(char))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	return;
}

static void			_read_data_fill(t_read_data *self, int fd)
{
	_read_data_allocate_intitial_value(self);
	_read_data_get_chunk(self, fd);
	while (self->is_read == FALSE)
	{
		if (self->total + INITIAL_CHUNK > self->capacity)
			_read_data_reallocate_value(self);
		_read_data_get_chunk(self, fd);
	}
	return;
}

t_read_data			read_data_ctor(int fd)
{
	t_read_data		*self;

	if ((self = (t_read_data *)ft_memalloc(sizeof(*self))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	_read_data_fill(self);
	return (self);
}

void				read_data_dtor(t_read_data **self)
{
	ft_memdel((void **)self);
	return;
}