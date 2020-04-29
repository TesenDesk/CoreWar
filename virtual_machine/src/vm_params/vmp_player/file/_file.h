/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _file.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:18:37 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/26 21:10:10 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILE_H
# define _FILE_H

# include "libft.h"
# include "errors.h"
# include "file.h"

# define INITIAL_CHUNK	128

typedef struct	s_file
{
	void		*data;
	ssize_t		total;
	ssize_t		capacity;
	char		*file_name;
	int			fd;
	int			is_opened;
	int			is_read;
}				t_file;

void			_file_read(t_file *self);
void			_file_open(t_file *self);
void			_file_close(t_file *self);

void			_file_allocate_intitial_value(t_file *self);
void			_file_reallocate_value(t_file *self);
void			_file_get_chunk(t_file *self);

#endif
