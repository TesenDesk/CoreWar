/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codegen_filling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:31:48 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/23 13:40:48 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_codegen.h"

/*
** TODO: Func never used.
*/

void			fill_empty_cell(t_codegen *data, int size)
{
	while (size)
	{
		ft_memcpy(&(data->code[data->add++]), "\0", 1);
		--size;
	}
}

void			fill_dirind_param(t_codegen *data, t_arg *param,
					char dir_type)
{
	unsigned int	num_arg;
	int				cell_size;
	short			s;

	num_arg = (unsigned int)ft_atol(token_get_value(arg_get_value(param)));
	if (arg_get_type(param) == TOKEN_TREG)
		cell_size = 1;
	else
		cell_size = arg_get_type(param) == TOKEN_TDIR_INT && dir_type == 1 ?
			4 : 2;
	rotate_bytes(&num_arg, cell_size);
	if (cell_size == 2)
	{
		s = (short)num_arg;
		ft_memcpy(&(data->code[data->add]), &s, cell_size);
	}
	else
		ft_memcpy(&(data->code[data->add]), &num_arg, cell_size);
	data->add+= cell_size;
}

void			fill_codes(int array_of_codes[NUM_OF_TOKENS])
{
	array_of_codes[TOKEN_AFF] = OP_AFF_CODE;
	array_of_codes[TOKEN_ST] = OP_ST_CODE;
	array_of_codes[TOKEN_STI] = OP_STI_CODE;
	array_of_codes[TOKEN_ADD] = OP_ADD_CODE;
	array_of_codes[TOKEN_SUB] = OP_SUB_CODE;
	array_of_codes[TOKEN_LD] = OP_LD_CODE;
	array_of_codes[TOKEN_LLD] = OP_LLD_CODE;
	array_of_codes[TOKEN_LDI] = OP_LDI_CODE;
	array_of_codes[TOKEN_LLDI] = OP_LLDI_CODE;
	array_of_codes[TOKEN_AND] = OP_AND_CODE;
	array_of_codes[TOKEN_OR] = OP_OR_CODE;
	array_of_codes[TOKEN_XOR] = OP_XOR_CODE;
	array_of_codes[TOKEN_LIVE] = OP_LIVE_CODE;
	array_of_codes[TOKEN_ZJMP] = OP_ZJMP_CODE;
	array_of_codes[TOKEN_FORK] = OP_FORK_CODE;
	array_of_codes[TOKEN_LFORK] = OP_LFORK_CODE;
}
