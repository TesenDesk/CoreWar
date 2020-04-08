/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vmp_state_due_to_state.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 22:14:58 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 22:15:29 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vmp_state.h"

int			_vmp_state_due_to_state(int state)
{
	if (state == IS_DUMP)
		state = SET_NBR_CYCLES;
	else if (state == SET_PLAYER_NAME)
		state = SET_FILE_NAME_WITH_ID;
	else
		state = VMP_INITIAL;
	return (state);
}