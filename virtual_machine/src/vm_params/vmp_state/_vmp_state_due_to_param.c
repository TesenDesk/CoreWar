/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vmp_state_due_to_param.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 22:16:44 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 22:17:09 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vmp_state.h"

int			_vmp_state_due_to_param(char *param)
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
