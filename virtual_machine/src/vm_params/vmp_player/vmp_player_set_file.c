/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v̶m̶p̶_̶p̶l̶a̶y̶e̶r̶_̶s̶e̶t̶_̶f̶i̶l̶e̶.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 21:07:27 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/26 21:09:42 by nikita_toro      ###   ########.fr       */
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
//	_vmp_player_precondition_check(self, file_name);
	self->file = file_new(file_name);
	return;
}