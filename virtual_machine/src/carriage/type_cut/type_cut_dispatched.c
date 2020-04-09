/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_cut_dispatched.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 22:29:21 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/09 23:57:02 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_type_cut.h"

void						type_cut_dispatched(long int *registers)
{
	int						state;
	static t_type_cutter	_carriage_type_cut_dispatcher[TYPES_BY_LEN_NB] =
	{
		_type_cut_char,
		_type_cut_short,
		_type_cut_int,
		_type_cut_long_int,
	};

	state = ft_powerof2rounddown(REG_SIZE);
	(*_carriage_type_cut_dispatcher[state])(registers);
	return;
}
