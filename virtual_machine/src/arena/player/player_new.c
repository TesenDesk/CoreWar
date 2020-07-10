/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:30:11 by yurezz            #+#    #+#             */
/*   Updated: 2020/07/04 17:56:44 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_player.h"

t_player		*player_new(t_vmp_player *vmp_player)
{
	t_player	*self;
	t_i_file	*file;

	file = vmp_player_file(vmp_player);
	file_data_check_valid(file);
	if ((self = (t_player *)ft_memalloc(sizeof(*self))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
//	self->name = vmp_player_name(vmp_player);
	self->text_name = file_data_name(file);
	self->text_comment = file_data_comment(file);
	self->code_size = file_code_size(file);
	self->code = file_data_code(file);
	return (self);
}
