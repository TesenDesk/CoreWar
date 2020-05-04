/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmp_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 21:07:27 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 22:17:41 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vmp_state.h"

int					vmp_state(char *param)
{
	static int		state;

//	if (state != VMP_INITIAL && param == NULL)
//		raise(__FILE__, __LINE__, ENOARGVAL);
//	if (state == VMP_INITIAL)
//		state = _vmp_state_due_to_param(param);
//	else
//		state = _vmp_state_due_to_state(state);
	return (state);
}
