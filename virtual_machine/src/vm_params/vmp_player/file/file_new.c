/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:28:46 by yurezz            #+#    #+#             */
/*   Updated: 2020/07/01 18:01:22 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_file.h"

tt_file			*file_new(char *file_name)
{
	tt_file		*self;

	if ((self = (tt_file *)ft_memalloc(sizeof(*self))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	self->file_name = file_name;
	prvt_file_open(self);
	prvt_file_read(self);
	prvt_file_close(self);
	return (self);
}
