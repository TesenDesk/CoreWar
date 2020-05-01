/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _file_reallocate_value.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 22:54:49 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 22:55:32 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_file.h"

void			_file_reallocate_value(tt_file *self)
{
	ssize_t			new_capacity;

	new_capacity = 2 * self->capacity;
	if (new_capacity > INT_MAX)
		exit (-1);
//		raise(__FILE__, __LINE__, ENOMEMORY);
	if (ft_realloc_safe(&(self->data), self->capacity, new_capacity) == FAILURE)
//		raise(__FILE__, __LINE__, ENOMEMORY);
		exit(-1);
	self->capacity = new_capacity;
	return;
}
