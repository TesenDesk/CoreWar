/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _file_allocate_initial_value.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 22:57:19 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 22:57:38 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_file.h"

void			_file_allocate_intitial_value(tt_file *self)
{
	if ((self->data = ft_memalloc(INITIAL_CHUNK * sizeof(char))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	self->capacity = INITIAL_CHUNK;
}
