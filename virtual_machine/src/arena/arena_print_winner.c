/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_print_winner.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 19:09:14 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/04 19:09:17 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_arena.h"

void	arena_print_winner(t_arena *self)
{
	player_print_winner(self->players[self->last_live_player - 1]);
}
