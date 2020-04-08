/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 21:32:30 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 21:33:35 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_file.h"

void			file_close(t_file *self)
{
	if (self->is_opened == FALSE)
		raise (__FILE__, __LINE__, EDOUBLECLOSE);
	if (close(self->fd) == FAILURE)
		raise(__FILE__, __LINE__, ECANNOTCLOSE);
	self->is_opened = FALSE;
	return;
}
