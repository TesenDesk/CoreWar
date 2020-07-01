/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_data_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:59:30 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/01 17:59:34 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_file.h"

char		*file_data_name(tt_file *self)
{
	char		*name_in_data;
	char		*name;

	name_in_data = (char*)(self->data)
		+ MAGIC_LENGTH;
	if (!(name = ft_strdup(name_in_data)))
		raise(__FILE__, __LINE__, ENOMEMORY);
	return (name);
}
