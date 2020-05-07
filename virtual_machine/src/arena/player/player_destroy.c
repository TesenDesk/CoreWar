/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 23:10:04 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 23:10:34 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_player.h"

void			player_destroy(t_player **self)
{

    free((*self)->text_name);
    free((*self)->text_comment);
//	code_destroy(&(*self)->code);
	ft_memdel((void**)self);
	return;
}
