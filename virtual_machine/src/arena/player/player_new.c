/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:30:11 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/26 21:36:24 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_player.h"

t_player		*player_new(t_vmp_player *vmp_player)
{
	t_player	*self;
	t_file		*file;

	file = vmp_player_file(vmp_player);
	file_data_precondition_check(file);
	if ((self = (t_player *)ft_memalloc(sizeof(*self))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	self->name = file_player_name(file);
	self->text_name = file_data_name(file);
	self->text_comment = file_data_comment(file);
	self->text_code = file_data_code(file);
	file_destroy(file);
	return (self);
}

