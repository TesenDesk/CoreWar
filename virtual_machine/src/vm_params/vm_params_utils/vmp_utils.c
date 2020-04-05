/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 21:07:27 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/05 18:51:53 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vmp_utils.h"

void			vmp_utils_check_if_file_is_available(char *file_name)
{
	int				fd;

	if ((fd = open(file_name, O_RDONLY)) == FAILURE)
		raise(__FILE__, __LINE__, EBADFILENAME);
	if (read(fd, NULL, 0) == FAILURE)
	{
		if (close(fd) == FAILURE)
			raise(__FILE__, __LINE__, ECANNOTCLOSE);
		raise(__FILE__, __LINE__, ECANNOTREAD);
	}
	if (close(fd) == FAILURE)
		raise(__FILE__, __LINE__, ECANNOTCLOSE);
	return;
}