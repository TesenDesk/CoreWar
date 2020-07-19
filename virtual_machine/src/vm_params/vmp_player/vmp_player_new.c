/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmp_player_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:28:46 by yurezz            #+#    #+#             */
/*   Updated: 2020/07/02 18:17:40 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_vmp_player.h"

t_vmp_player		*vmp_player_new(int p_name, char *file_name)
{
	t_vmp_player	*self;

	if ((self = (t_vmp_player *)ft_memalloc(sizeof(t_vmp_player))) == NULL)
		ft_raise(__FILE__, __LINE__, ENOMEMORY);
	self->p_name = p_name;
	if (file_name != PFILE_MOCK)
		self->file = file_new(file_name);
	return (self);
}
