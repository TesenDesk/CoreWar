/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _file_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 21:42:24 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/21 21:11:11 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_file.h"

void			_file_read(tt_file *self)
{
	int 		chunk;

    chunk = 0;
	_file_allocate_intitial_value(self);
	self->total = 0;
	while ((chunk = read(self->fd, self->data + self->total, INITIAL_CHUNK)) > 0)
	{
		self->total += chunk;
		if (self->total == self->capacity)
			_file_reallocate_value(self);
		int i = 0;
		while (i < INITIAL_CHUNK)
		{
			if (i % 16 == 0)
				printf("\n");
			else if(i % 2 == 0)
				printf("  ");
			if (*((unsigned char*)(self->data + self->total  - chunk + i)) < 16)
				printf("0");
			printf("%x",  *((unsigned char*)(self->data + self->total  - chunk + i)));
			i += 1;
		}

	}
	return;
}
