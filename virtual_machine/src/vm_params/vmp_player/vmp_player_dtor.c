/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmp_player_dtor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 22:04:06 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 22:04:20 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vmp_player.h"

void				vmp_player_dtor(t_vmp_player **self)
{
	if ((*self)->file != PFILE_MOCK)
		file_dtor(&(*self)->file);
	ft_memdel((void **)self);
	return;
}
