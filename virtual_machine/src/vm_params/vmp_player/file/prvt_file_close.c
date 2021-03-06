/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_file_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:19:22 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/01 18:19:27 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_file.h"

void			prvt_file_close(t_i_file *self)
{
	if (self->is_opened == FALSE)
		ft_raise(__FILE__, __LINE__, EDOUBLECLOSE);
	if (close(self->fd) == FAIL)
		ft_raise(__FILE__, __LINE__, ECANNOTCLOSE);
	self->is_opened = FALSE;
	return ;
}
