/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmp_player_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 22:04:06 by yurezz            #+#    #+#             */
/*   Updated: 2020/07/04 16:38:01 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_vmp_player.h"

void				vmp_player_destroy(t_vmp_player **self)
{
	if ((*self)->file != PFILE_MOCK)
		file_destroy(&(*self)->file);
	ft_memdel((void **)self);
	return ;
}
