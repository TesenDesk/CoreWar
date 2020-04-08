/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _file_get_chunk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 22:55:59 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 22:56:24 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_file.h"

void			_file_get_chunk(t_file *self)
{
	ssize_t			chunk;

	if ((chunk = read(self->fd, self->data, INITIAL_CHUNK)) == NULL)
		raise(__FILE__, __LINE__, ECANNOTREAD);
	self->total += chunk;
	if (chunk == 0)
		self->is_read = TRUE;
	return;
}
