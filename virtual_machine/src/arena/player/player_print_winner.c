/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_print_winner.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 18:04:10 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/04 18:04:20 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_player.h"

void		player_print_winner(t_player *self)
{
	printf("Contestant %i, \"%s\", has won !\n", self->name, self->text_name);
	return ;
}
