/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmp_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 21:07:27 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/06 00:21:36 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vmp_state.h"

static int			_vmp_state_due_to_param(char *param)
{
	int				state;

	if (param == NULL)
		state = VMP_STOP;
	else if (ft_strequ(P_SHORT_DUMP, param) || ft_strequ(P_LONG_DUMP, param))
		state = IS_DUMP;
	else if (ft_strequ(P_SHORT_NAME, param) || ft_strequ(P_LONG_NAME, param))
		state = SET_PLAYER_NAME;
	else
		state = SET_FILE_NAME_WITHOUT_ID;
	return (state);
}

static int			_vmp_state_due_to_state(int state)
{
	if (state == IS_DUMP)
		state = SET_NBR_CYCLES;
	else if (state == SET_PLAYER_NAME)
		state = SET_FILE_NAME_WITH_ID;
	else
		state = VMP_INITIAL;
	return (state);
}

int					vmp_state(char *param)
{
	static int		state;

	if (state != VMP_INITIAL && param == NULL)
		raise(__FILE__, __LINE__, ENOARGVAL);
	if (state == VMP_INITIAL)
		state = _vmp_state_due_to_param(param);
	else
		state = _vmp_state_due_to_state(state);
	return (state);
}

