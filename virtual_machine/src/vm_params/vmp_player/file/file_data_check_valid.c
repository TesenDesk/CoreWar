/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_data_check_valid.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:59:08 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/01 17:59:08 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_file.h"

static int		file_check_data_size(t_i_file *self)
{
	unsigned int			min_size;
	unsigned int			code_size;
	char					*pointer_code_size;
	unsigned int			data_file_size;

	min_size = MAGIC_LENGTH
		+ PROG_NAME_LENGTH
		+ NULL_LENGTH
		+ CHAMP_SIZE_LENGTH
		+ COMMENT_LENGTH
		+ NULL_LENGTH;
	if (self->total < min_size)
		return (FAILURE);
	pointer_code_size = (char*)(self->data)
			+ MAGIC_LENGTH
			+ PROG_NAME_LENGTH
			+ NULL_LENGTH;
	code_size = *(int*)pointer_code_size;
	code_size = (int)((code_size << 24) | ((code_size & 0xff00) << 8)
			| ((code_size & 0xff0000) >> 8) | (code_size >> 24));
	data_file_size = min_size + code_size;
	if (code_size > CHAMP_MAX_SIZE || data_file_size != self->total)
		return (FAILURE);
	return (SUCCESS);
}

static int		file_data_check_nulls(t_i_file *self)
{
	char		*pointer_first_null;
	char		*pointer_second_null;
	int			first_null;
	int			second_null;

	pointer_first_null = (char*)(self->data)
		+ MAGIC_LENGTH
		+ PROG_NAME_LENGTH;
	pointer_second_null = (char*)(self->data)
		+ MAGIC_LENGTH
		+ PROG_NAME_LENGTH
		+ NULL_LENGTH
		+ CHAMP_SIZE_LENGTH
		+ COMMENT_LENGTH;
	first_null = *((int*)pointer_first_null);
	second_null = *((int*)pointer_second_null);
	if (first_null || second_null)
		return (FAILURE);
	return (SUCCESS);
}

static int		file_data_magic_header_check(t_i_file *self)
{
	unsigned int			data_magic_header;

	data_magic_header = *((unsigned int*)(self->data));
	data_magic_header = (int)((data_magic_header << 24)
			| ((data_magic_header & 0xff00) << 8)
			| ((data_magic_header & 0xff0000) >> 8)
			| (data_magic_header >> 24));
	if (data_magic_header != COREWAR_EXEC_MAGIC)
		return (FAILURE);
	return (SUCCESS);
}

int				file_data_check_valid(t_i_file *self)
{
	if (file_check_data_size(self))
		ft_raise(__FILE__, __LINE__, EWRONGSIZE);
	else if (file_data_check_nulls(self))
		ft_raise(__FILE__, __LINE__, ENONULLS);
	else if (file_data_magic_header_check(self))
		ft_raise(__FILE__, __LINE__, ENOMAGICH);
	return (SUCCESS);
}
