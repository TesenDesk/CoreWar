/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_file_allocate_initial_value.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 17:37:50 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/26 16:07:28 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_file.h"

void			prvt_file_allocate_initial_value(t_i_file *self)
{
	if ((self->data = ft_memalloc(sizeof(char) * INITIAL_CHUNK)) == NULL)
		ft_raise(__FILE__, __LINE__, ENOMEMORY);
	self->capacity = INITIAL_CHUNK;
}
