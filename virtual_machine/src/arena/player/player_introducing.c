/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_introducing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 17:54:39 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/13 17:03:23 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_player.h"

void			player_introducing(t_player *self)
{
	char		*player_num;
	char		*weighing;

	printf("* Player %i, weighing %i bytes, \"%s\" (\"%s\") !\n", self->name,
			self->code_size, self->text_name, self->text_comment);
	return ;
}
