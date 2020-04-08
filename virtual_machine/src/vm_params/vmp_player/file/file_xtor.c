/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_xtor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:28:46 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 21:48:47 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_file.h"

t_file			*file_ctor(char *file_name)
{
	t_file		*self;

	if ((self = (t_file *)ft_memalloc(sizeof(*self))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	self->file_name = file_name;
	_file_open(self);	
	_file_read(self);
	_file_close(self);
	return (self);
}

