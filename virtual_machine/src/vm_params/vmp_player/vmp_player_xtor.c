/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmp_player_xtor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:28:46 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 21:30:27 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vmp_player.h"



t_vmp_player		*vmp_player_ctor(int player_name, char *file_name)
{
	t_vmp_player	*self;

	if ((self = (t_vmp_player *)ft_memalloc(sizeof(*self))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	self->player_name = player_name;
	self->file_name = file_name;
	self->file = file_ctor(file_name);
	return (self);
}

void				vmp_player_dtor(t_vmp_player **self)
{
	vmp_player_close((*self)->fd);
	ft_memdel((void **)self);
	return;
}
