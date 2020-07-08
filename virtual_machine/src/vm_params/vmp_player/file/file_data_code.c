/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_data_code.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:00:19 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/01 18:00:19 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_file.h"

void		*file_data_code(t_i_file *self)
{
	char				*code_in_data;
	char				*code;
	char				*code_size_in_data;
	unsigned int		code_size;

	code_in_data = (char*)(self->data)
		+ MAGIC_LENGTH
		+ PROG_NAME_LENGTH
		+ NULL_LENGTH
		+ CHAMP_SIZE_LENGTH
		+ COMMENT_LENGTH
		+ NULL_LENGTH;
	code_size_in_data = (char*)(self->data)
		+ MAGIC_LENGTH
		+ PROG_NAME_LENGTH
		+ NULL_LENGTH;
	code_size = *(unsigned int*)code_size_in_data;
	code_size = (int)((code_size << 24)
		| ((code_size & 0xff00) << 8)
		| ((code_size & 0xff0000) >> 8)
		| (code_size >> 24));
	if (!(code = ft_memalloc(code_size)))
		raise(__FILE__, __LINE__, ENOMEMORY);
	ft_memcpy(code, code_in_data, code_size);
	return (code);
}
