/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 23:10:04 by yurezz            #+#    #+#             */
/*   Updated: 2020/07/04 17:59:24 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_player.h"

void			player_destroy(t_player **self)
{
	free((*self)->text_name);
	free((*self)->text_comment);
	free((*self)->code);
	ft_memdel((void**)self);
	return ;
}
