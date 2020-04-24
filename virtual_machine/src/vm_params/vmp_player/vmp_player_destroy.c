/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmp_player_dtor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 22:04:06 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 22:51:29 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vmp_player.h"
#include "file.h"

void				vmp_player_destroy(t_vmp_player **self)
{
	if ((*self)->file != PFILE_MOCK)
		file_destroy(&(*self)->file);
	ft_memdel((void **)self);
	return;
}
