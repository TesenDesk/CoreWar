/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_file_open.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:19:05 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/01 18:19:06 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_file.h"

void			prvt_file_open(t_i_file *self)
{
	if (self->is_opened == TRUE)
		raise(__FILE__, __LINE__, EDOUBLEOPENNING);
	if ((self->fd = open(self->file_name, O_RDONLY)) == FAILURE)
		raise(__FILE__, __LINE__, ECANNOTREAD);
	self->is_opened = TRUE;
	return ;
}
