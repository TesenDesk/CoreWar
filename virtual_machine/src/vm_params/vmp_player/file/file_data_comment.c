/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_data_comment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:59:45 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/01 17:59:46 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_file.h"

char		*file_data_comment(t_i_file *self)
{
	char		*comment_in_data;
	char		*comment;

	comment_in_data = (char*)(self->data)
		+ MAGIC_LENGTH
		+ PROG_NAME_LENGTH
		+ NULL_LENGTH
		+ CHAMP_SIZE_LENGTH;
	if (!(comment = ft_strdup(comment_in_data)))
		ft_raise(__FILE__, __LINE__, ENOMEMORY);
	return (comment);
}
