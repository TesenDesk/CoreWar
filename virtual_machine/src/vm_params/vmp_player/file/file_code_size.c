/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_code_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:00:25 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/01 18:04:28 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_file.h"

size_t			file_code_size(t_i_file *self)
{
	char				*code_size_in_data;
	unsigned int		code_size;

	code_size_in_data = (char*)(self->data)
		+ MAGIC_LENGTH
		+ PROG_NAME_LENGTH
		+ NULL_LENGTH;
	code_size = (*(int*)code_size_in_data);
	code_size = (int)((code_size << 24)
		| ((code_size & 0xff00) << 8)
		| ((code_size & 0xff0000) >> 8)
		| (code_size >> 24));
	return (code_size);
}
