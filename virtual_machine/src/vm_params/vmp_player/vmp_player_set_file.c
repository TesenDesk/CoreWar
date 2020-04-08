/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmp_player_set_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 21:07:27 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 22:51:04 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vmp_player.h"

static void		_vmp_player_precondition_check(t_vmp_player *self,
					char *file_name)
{
	if (self->file != PFILE_MOCK)
		raise(__FILE__, __LINE__, EDANGLINGPTR);
	return;
}

void			vmp_player_set_file(t_vmp_player *self, char *file_name)
{
	_vmp_player_precondition_check(self, file_name);
	self->file = file_new(file_name);
	return;
}
