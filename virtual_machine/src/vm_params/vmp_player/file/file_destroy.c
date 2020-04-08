/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 21:41:19 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 23:32:39 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_file.h"

void				file_destroy(t_file **self)
{
	if ((*self)->is_opened)
		_file_close(*self);
	ft_memdel((void **)self);
	return;
}
