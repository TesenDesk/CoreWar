/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmp_player_xtor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:28:46 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 13:33:30 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vmp_player.h"

static ssize_t		_vmp_player_read_chunk(t_vmp_player *self)
{
	ssize_t			chunk;

	if ((chunk = read(self->fd, self->data, BEST_SIZE)) == NULL)
		raise(__FILE__, __LINE__, ECANNOTREAD);
	return (chunk);
}

static void			_vmp_player_allocate_enough_for_data(t_vmp_player *self)
{
	ssize_t			new_size;

	new_size = self->size == 0 ? BEST_SIZE : 2 * self->size;
	if (new_size > INT_MAX)
		raise(__FILE__, __LINE__, ENOMEMORY);
	if (ft_realloc_safe(&self->data, self->size, new_size) == FAILURE)
		raise(__FILE__, __LINE__, ENOMEMORY);
	return;
}

void				_vmp_player_read(t_vmp_player *self)
{
	ssize_t			chunk;

	if ((self->data = ft_memalloc(BEST_SIZE * sizeof(char))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	_vmp_player_read_chunk(self);
	while (chunk != SUCCESS)
	{
		self->size += chunk;
		if ((chunk = read(self->fd, self->data, BEST_SIZE)) == NULL)
			raise(__FILE__, __LINE__, ECANNOTREAD);
		
	}
	return;
}

t_vmp_player		*vmp_player_ctor(int player_name, char *file_name)
{
	t_vmp_player	*self;

	if ((self = (t_vmp_player *)ft_memalloc(sizeof(*self))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	self->player_name = player_name;
	self->file_name = file_name;
	_vmp_player_read(self);
	return (self);
}

void				vmp_player_dtor(t_vmp_player **self)
{
	vmp_player_close((*self)->fd);
	ft_memdel((void **)self);
	return;
}
