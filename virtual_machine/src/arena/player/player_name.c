/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 20:01:21 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 23:11:38 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_player.h"

int			player_name(t_player *self)
{
	int		name;

	name = self->name;
	return (name);
}
