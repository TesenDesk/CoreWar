/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_file_reallocate_value.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:18:16 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/01 18:18:17 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_file.h"

void			prvt_file_reallocate_value(t_i_file *self)
{
	ssize_t			new_capacity;

	new_capacity = 2 * self->capacity;
	if (new_capacity > INT_MAX)
		raise(__FILE__, __LINE__, ENOMEMORY);
	if (ft_realloc_safe(&(self->data), self->capacity, new_capacity) == FAILURE)
		raise(__FILE__, __LINE__, ENOMEMORY);
	self->capacity = new_capacity;
	return ;
}
