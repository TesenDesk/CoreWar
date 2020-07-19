/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmp_player_set_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 21:07:27 by yurezz            #+#    #+#             */
/*   Updated: 2020/07/02 18:21:48 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_vmp_player.h"

static void		prvt_vmp_player_precondition_check(t_vmp_player *self,
					char *file_name)
{
	if (self->file != PFILE_MOCK)
		ft_raise(__FILE__, __LINE__, EDANGLINGPTR);
	return ;
}

void			vmp_player_set_file(t_vmp_player *self, char *file_name)
{
	prvt_vmp_player_precondition_check(self, file_name);
	self->file = file_new(file_name);
	return ;
}
