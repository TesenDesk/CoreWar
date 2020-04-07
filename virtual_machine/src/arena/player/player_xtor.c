/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_xtor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:30:11 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/07 16:43:34 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_player.h"

t_player		*player_ctor(t_vmp_player *vmp_player)
{
	t_player	*self;

	if ((self = (t_player *)ft_memalloc(sizeof(*self))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	self->id = _player_id_from_vmp_player(vmp_player);
	self->text_name = _player_text_name_from_vmp_player(vmp_player);
	self->text_name = _player_text_comment_from_vmp_player(vmp_player);
	self->text_name = code_ctor(vmp_player);
	return (self);
}

void			player_dtor(t_player **self)
{
	code_dtor(&(*self)->code);
	ft_memdel(self);
	return;
}