/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:28:46 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/26 21:10:29 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_file.h"

// t_file			*file_new(int player_name, char *file_name)
t_file			*file_new(char *file_name)
{
	t_file		*self;

	if ((self = (t_file *)ft_memalloc(sizeof(*self))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	// self->player_name = player_name;
	self->file_name = file_name;
	_file_open(self);
	_file_read(self);
	_file_close(self);
	return (self);
}
