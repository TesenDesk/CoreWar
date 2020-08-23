/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codegen_xtor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:14:57 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/23 14:55:35 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_codegen.h"

t_codegen		*codegen_ctor(t_hash_map *labels_free,
									t_header *header)
{
	t_codegen	*code;

	code = ft_memalloc(sizeof(t_codegen));
	code->labels_free = labels_free;
	if (!(code->labels_ptrs = (t_vector*)ft_memalloc(sizeof(t_vector))))
		exit(-1);
	ft_vector_init(code->labels_ptrs);
	code->header = header;
	code->code = ft_memalloc(sizeof(char) * 1000000);
	if (!(code->junk_container = (t_vector*)ft_memalloc(sizeof(t_vector))))
		exit(-1);
	if (ft_vector_init(code->junk_container) == FAILURE)
		exit(-1);
	return (code);
}

void			codegen_dtor(t_codegen *code)
{
	if (code)
	{
		if (code->labels_ptrs)
		{
			ft_vector_free_data(code->labels_ptrs, label_dtor);
			free(code->labels_ptrs);
			code->labels_ptrs = NULL;
		}
		ft_vector_free_data(code->junk_container, ft_memdel);
		free(code->junk_container);
		free(code->exec);
		code->exec = NULL;
		free(code->code);
		code->code = NULL;
		free(code);
		code = NULL;
	}
}

void			label_dtor(void **data)
{
	if (data)
	{
		if (*data)
		{
			free(*data);
			*data = NULL;
		}
	}
}

int				champ_exec_constructor(t_codegen *data)
{
	size_t			total_size;
	int				i;
	unsigned int	tmp_size;

	i = 0;
	codegen_ending(data);
	total_size = (PROG_NAME_LENGTH + COMMENT_LENGTH) + 16 + data->code_size;
	if (!(data->exec = ft_memalloc(total_size)))
		return (0);
	rotate_four_bytes(&data->header->magic);
	ft_memcpy(&data->exec[i], &data->header->magic, 4);
	i += 4;
	codegen_add_champ_name(&data->exec[i], data->header);
	i += (PROG_NAME_LENGTH) + 4;
	tmp_size = data->code_size;
	rotate_four_bytes(&tmp_size);
	ft_memcpy(&data->exec[i], &tmp_size, 4);
	i += 4;
	codegen_add_champ_comment(&data->exec[i], data->header);
	i += (COMMENT_LENGTH) + 4;
	ft_memcpy(&data->exec[i], data->code, data->code_size);
	return (total_size);
}
