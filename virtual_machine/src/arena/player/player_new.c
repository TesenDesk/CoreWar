/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:30:11 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/28 20:21:35 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_player.h"
#include "vmp_player.h"

t_player		*player_new(t_vmp_player *vmp_player)
{
	t_player	*self;
	tt_file		*file;

	file = vmp_player_file(vmp_player);
	file_data_check_valid(file);
	if ((self = (t_player *)ft_memalloc(sizeof(*self))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	self->name = vmp_player_name(vmp_player);
	self->text_name = file_data_name(file);
	self->text_comment = file_data_comment(file);
	self->code = file_data_code(file);
    vmp_player_destroy(&vmp_player);
    return (self);
}

