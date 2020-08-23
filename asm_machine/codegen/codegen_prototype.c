/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codegen_prototype.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:09:23 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/23 13:48:09 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_codegen.h"

void			recast_params_types(t_codegen *data, t_expr *q)
{
	int			args[3];
	int			i;
	int			arg_type;

	args[0] = 0;
	args[1] = 0;
	args[2] = 0;
	i = FIRST_ARG;
	while (i <= THIRD_ARG)
	{
		arg_type = expr_get_arg_type(q, i);
		if (arg_type == TOKEN_TIND_INT || arg_type == TOKEN_TIND_LAB)
			args[i - 1] = T_IND_CODE;
		else if (arg_type == TOKEN_TDIR_INT || arg_type == TOKEN_TDIR_LAB)
			args[i - 1] = T_DIR_CODE;
		else if (arg_type == TOKEN_TREG)
			args[i - 1] = T_REG_CODE;
		i++;
	}
	add_params_types(data, args[0], args[1], args[2]);
}

int				bytesize(int num)
{
	int			ans;

	ans = 1;
	while (num >>= 1)
		ans += 1;
	return (!(ans % 8) ? (ans / 8) : (ans / 8) + 1);
}

void			cut_num_arg(int *num_arg, int param_type, char dir_type)
{
	if (param_type == TOKEN_TREG)
	{
		if (*num_arg > 255 || *num_arg < -256)
			exit(-1);
		return ;
	}
}

void			do_something_in_cycle(t_codegen *data, t_expr *q)
{
	int			i;
	t_arg		*curr_arg;
	int			arg_type;

	i = 1;
	while (i - 1 < expr_get_arg_size(q) && expr_get_arg_type(q, i))
	{
		arg_type = expr_get_arg_type(q, i);
		curr_arg = expr_get_arg(q, i++);
		add_param(data, curr_arg, (char)expr_get_size(q));
		if (arg_type == TOKEN_TREG)
			data->code_size += 1;
		else if (arg_type == TOKEN_TIND_LAB
				|| arg_type == TOKEN_TIND_INT
				|| ((arg_type == TOKEN_TDIR_LAB
				|| arg_type == TOKEN_TDIR_INT)
				&& expr_get_size(q) == 2))
			data->code_size += 2;
		else
			data->code_size += 4;
	}
}

int				ar_len(char *ar)
{
	int		res;

	res = 0;
	while (ar != NULL)
	{
		ar += 1;
		res += 1;
	}
	return (res);
}
