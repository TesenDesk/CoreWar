/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmp_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 21:07:27 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/06 17:26:39 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vmp_player.h"

void			vmp_player_set_file_name(t_vmp_player *self, char *file_name)
{
	self->file_name = file_name;
	return;
}

void			vmp_player_check_if_readable(t_vmp_player *self)
{
	if (self->is_opened == FALSE)
		raise(__FILE__, __LINE__, EREADNOTOPENED);
	if (read(self->fd, NULL, 0) == FAILURE)
	{
		vmp_player_close(self);
		raise(__FILE__, __LINE__, ECANNOTREAD);
	}
	return;
}

void			vmp_player_open(t_vmp_player *self)
{
	if (self->is_opened == TRUE)
		raise(__FILE__, __LINE__, EDOUBLEOPENNING);
	if ((self->fd = open(self->file_name, O_RDONLY)) == FAILURE)
		raise(__FILE__, __LINE__, EBADFILENAME);
	self->is_opened = TRUE;
	return;
}

void			vmp_player_close(t_vmp_player *self)
{
	if (self->is_opened == FALSE)
		raise (__FILE__, __LINE__, EDOUBLECLOSE);
	if (close(self->fd) == FAILURE)
		raise(__FILE__, __LINE__, ECANNOTCLOSE);
	self->is_opened = FALSE;
	return;
}