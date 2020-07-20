/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_live_verbosity.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:04:11 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/13 17:04:12 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_player.h"

void			player_live_verbosity(t_player *self)
{
	if (vm_verbosity_lvl() & 1)
		printf("Player %i (%s) is said to be alive\n", self->name,
												self->text_name);
}
