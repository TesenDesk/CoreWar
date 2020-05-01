/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 21:41:19 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/24 19:38:04 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_file.h"

void				file_destroy(tt_file **self)
{
	ft_memdel(&((*self)->data));
	ft_memdel(&((*self)->file_name));
	ft_memdel((void **)self);
	return;
}
