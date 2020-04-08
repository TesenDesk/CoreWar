/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:30:11 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 23:11:10 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_player.h"

static void		player_new_precondition_check(t_vmp_player *vmp_player)
{
	наличие magic header'а'
	соответствие указанного размера кода реальному и так далее
	максимальному размеру исполняемого кода
	return;
}

t_player		*player_new(t_vmp_player *vmp_player)
{
	t_player	*self;

	player_new_precondition_check(vmp_player);
	if ((self = (t_player *)ft_memalloc(sizeof(*self))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	self->name = _player_name_from_vmp_player(vmp_player);
	self->text_name = _player_text_name_from_vmp_player(vmp_player);
	self->text_name = _player_text_comment_from_vmp_player(vmp_player);
	self->text_name = code_new(vmp_player);
	return (self);
}

