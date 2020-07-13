/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage_is_alive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 21:01:54 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/04 21:02:22 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_carriage.h"

int		carriage_is_alive(t_carriage *self, int cycles_to_die, int counter)
{
	if (cycles_to_die <= 0
	|| (counter - self->last_live_cycle) >= cycles_to_die)
		return (FALSE);
	else
		return (TRUE);
}
