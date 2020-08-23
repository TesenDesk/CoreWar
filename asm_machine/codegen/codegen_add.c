/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codegen_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:34:39 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/23 13:40:49 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_codegen.h"

void		write_address_to_free_label(t_codegen *data, t_expr *label)
{
	t_code_addr	*tmp;
	t_token		*token;

	token = expr_get_arg_value(label, LABEL_ARG);
	if (!(tmp = (t_code_addr*)ft_memalloc(sizeof(t_code_addr))))
		exit(-1);
	tmp->addr = data->add;
//	t_token *a = ft_hash_map_get(data->labels_free, token_get_value(token));
//	token_destructor(&a);
//	a = NULL;
//	ft_hash_map_dtor(&map);
//	printf("%s   %s\n",token_get_value(token),  a);
	ft_vector_add(data->junk_container, tmp);
	ft_hash_map_set_content(data->labels_free, token_get_value(token), (tmp));
}

void		add_address_to_arg_label(t_codegen *data, t_arg *arg, int shift)
{
	t_label_data *label;

	if (!(label = (t_label_data*)malloc(sizeof(t_label_data))))
		exit(-1);
	label->name = token_get_value(arg_get_value(arg));
	label->add = data->add + shift;
	label->instruction_begining = data->cur_instruction_addr;
	label->param_type = arg_get_type(arg);
	label->size = data->cur_instruction_dirsize;
	ft_vector_add(data->labels_ptrs, label);
}

void		add_param(t_codegen *data, t_arg *param, char dir_type)
{
	int			arg;
	int			shift;
	int			arg_type;

	arg = 0;
	arg_type = arg_get_type(param);
	if (arg_type == TOKEN_TIND_LAB || arg_type == TOKEN_TDIR_LAB)
	{
		if ((arg_type == TOKEN_TDIR_LAB && dir_type == 2)
		|| arg_type == TOKEN_TIND_LAB)
			shift = 2;
		else
			shift = 4;
		add_address_to_arg_label(data, param, 0);
		data->add += shift;
	}
	else
		fill_dirind_param(data, param, dir_type);
}

void		map_expr_to_code(t_expr *expr)
{
	static int	array_of_exprcodes[NUM_OF_TOKENS];
	int			new_type;

	if (array_of_exprcodes[TOKEN_LFORK])
		;
	else
		fill_codes(array_of_exprcodes);
	new_type = array_of_exprcodes[expr_get_arg_type(expr, OP_NAME)];
	expr_set_type(expr, new_type);
}

void		add_params_types(t_codegen *data, int first_arg, int second_arg,
									int third_arg)
{
	int			res;

	res = 0;
	res |= first_arg << 6;
	res |= second_arg << 4;
	res |= third_arg << 2;
	data->code[data->add++] = (char)res;
}
