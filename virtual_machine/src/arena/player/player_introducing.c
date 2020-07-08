/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_introducing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 17:54:39 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/04 17:54:48 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_player.h"

void			player_introducing(t_player *self)
{
	char		*player_num;
	char		*weighing;

	write(1, "* Player ", 9);
	player_num = ft_itoa(self->name);
	write(1, player_num, ft_strlen(player_num));
	free(player_num);
	write(1, ", weighing ", 11);
	weighing = ft_itoa(self->code_size);
	write(1, weighing, ft_strlen(weighing));
	free(weighing);
	write(1, " bytes, \"", 9);
	write(1, self->text_name, ft_strlen(self->text_name));
	write(1, "\" (\"", 4);
	write(1, self->text_comment, ft_strlen(self->text_comment));
	write(1, "\") !\n", 5);
	return ;
}
