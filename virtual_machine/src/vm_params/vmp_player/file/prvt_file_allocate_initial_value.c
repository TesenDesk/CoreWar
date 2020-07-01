/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _file_allocate_initial_value.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:59:59 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/01 17:59:59 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_file.h"

void			prvt_file_allocate_intitial_value(tt_file *self)
{
	if ((self->data = ft_memalloc(INITIAL_CHUNK * sizeof(char))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	self->capacity = INITIAL_CHUNK;
}
