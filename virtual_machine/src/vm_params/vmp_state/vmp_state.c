/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmp_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 21:07:27 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/05 11:48:07 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vmp_state.h"

int					vmp_state(char *param)
{
	static int		state;

	if (param == NULL)
	{
		if (SET_NBR_CYCLES <= state && state <= SET_FILE_NAME)
			raise(__FILE__, __LINE__, ENOARGVAL);
		else
			state = VMP_STOP;
	}
	else if (SET_NBR_CYCLES <= state && state <= SET_FILE_NAME)
		state = state == SET_PLAYER_NAME ? SET_FILE_NAME : VMP_INITIAL;
	else
	{
		if (
			ft_strequ(P_SHORT_DUMP, param) || ft_strequ(P_LONG_DUMP, param))
			state = SET_NBR_CYCLES;
		else if (
			ft_strequ(P_SHORT_NAME, param) || ft_strequ(P_LONG_NAME, param))
			state = SET_PLAYER_NAME;
		else
			state = SET_FILE_NAME;
	}
	return (state);
}

