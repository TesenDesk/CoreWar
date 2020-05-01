/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmp_player_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:28:46 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/25 18:41:00 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vmp_player.h"
#include "file.h"

t_vmp_player		*vmp_player_new(int player_name, char *file_name)
{
	t_vmp_player	*self;

	if ((self = (t_vmp_player *)ft_memalloc(sizeof(*self))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	self->player_name = player_name;
	if (file_name != PFILE_MOCK)
		self->file = file_new(file_name);
	return (self);
}
