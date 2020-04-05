/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vm_params_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 01:17:29 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/06 01:25:31 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

void					_vm_params_parse(t_vm_params *self, char **params)
{
	int					curr_player_name;
	int					state;
	static t_sm_parser	vtable[NBR_OF_VIRTUAL_METHODS] =
	{
		_vm_params_set_mock,
		_vm_params_set_is_dump,
		_vm_params_set_player_name,
		_vm_params_set_file_name_without_id,
		_vm_params_set_nbr_cycles,
		_vm_params_set_file_name_with_id,
	};

	while ((state = vmp_state(*params)) != VMP_STOP)
	{
		vtable[state](self, *params);
		++(*params);
	}
	return ;
}
