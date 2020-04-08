/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 21:33:46 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 21:34:21 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_file.h"

void			file_open(t_file *self)
{
	if (self->is_opened == TRUE)
		raise(__FILE__, __LINE__, EDOUBLEOPENNING);
	if ((self->fd = open(self->file_name, O_RDONLY)) == FAILURE)
		raise(__FILE__, __LINE__, EBADFILENAME);
	self->is_opened = TRUE;
	return;
}
