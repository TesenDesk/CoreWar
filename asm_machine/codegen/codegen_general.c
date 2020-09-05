/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codegen_general.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:29:22 by ftothmur          #+#    #+#             */
/*   Updated: 2020/09/05 21:05:19 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_codegen.h"

void			codegen_codegen(t_codegen *data, t_expr *q)
{
	if (expr_get_type(q) == EXPR_LABEL_W)
		write_address_to_free_label(data, q);
	else if (expr_get_type(q) != EXPR_EOF)
	{
		expr_set_size(q);
		map_expr_to_code(q);
		data->cur_instruction_addr = data->add;
		data->cur_instruction_code = expr_get_type(q);
		data->cur_instruction_dirsize = expr_get_size(q);
		data->code[data->add++] = expr_get_type(q);
		data->code_size += 1;
		if (expr_get_type(q) != OP_LIVE_CODE && expr_get_type(q) != OP_ZJMP_CODE
			&& expr_get_type(q) != OP_FORK_CODE && expr_get_type(q) !=
			OP_LFORK_CODE)
		{
			recast_params_types(data, q);
			data->code_size += 1;
		}
		do_something_in_cycle(data, q);
	}
}

void			codegen_ending(t_codegen *data)
{
	int				i;
	t_label_data	*ld;
	int				tmp;
	int				cell_size;
	t_c_add			*addr;

	i = -1;
	while ((ld = ft_vector_get(data->labels_ptrs, ++i)))
	{
		if (!(addr = (t_c_add *)ft_hash_map_get(data->labels_free, ld->name)))
		{
			ft_printf("no free label %s\n",
				((t_label_data *)data->labels_ptrs->items[i])->name);
			exit(-1);
		}
		tmp = (int)(addr->addr - ld->instruction_begining);
		if (ld->param_type == TOKEN_TIND_LAB)
			tmp %= IDX_MOD;
		cell_size = (ld->param_type == TOKEN_TDIR_LAB && ld->size == 1) ? 4 : 2;
		rotate_bytes((unsigned int*)&tmp, cell_size);
		if (cell_size == 2)
			ft_memcpy(&(data->code[ld->codegen_add]), (short *)&tmp, cell_size);
		else
			ft_memcpy(&(data->code[ld->codegen_add]), &tmp, cell_size);
	}
}

void			write_code_to_file(char *exec, int code_size, char *filename)
{
	int		fd;
	char	*root;
	char	*new_name;

	if (!(root = ft_memalloc(ft_strlen(filename) - 1)))
		exit(-1);
	if (ft_strncmp(filename + ft_strlen(filename) - 2, ".s", 2) != 0)
	{
		ft_printf("bad filename or format\n");
		exit(-1);
	}
	root = ft_strncpy(root, filename, ft_strlen(filename) - 2);
	new_name = ft_strjoin(root, ".cor");
	free(root);
	if (!(fd = open(new_name, O_WRONLY | O_CREAT, S_IWUSR | S_IRUSR)))
	{
		ft_printf("can' open/create a file\n");
		exit(-1);
	}
	write(fd, exec, code_size);
	ft_printf("Writing output program to %s\n", new_name);
	free(new_name);
}

void			generate_code(t_hash_map *map, t_vector *text, char *filename)
{
	t_codegen	*codegen;
	t_header	header;
	int			index;
	int			size;

	index = 2;
	init_header(&header, text);
	codegen = codegen_ctor(map, &header);
	while (index < text->total)
		codegen_codegen(codegen, text->items[index++]);
	size = champ_exec_constructor(codegen);
	write_code_to_file(codegen->exec, size, filename);
	codegen_dtor(codegen);
}
