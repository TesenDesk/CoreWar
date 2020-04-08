/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _file.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:18:37 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 21:37:36 by yurezz           ###   ########.fr       */
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
	int			fd;
	int			is_opened;
	int			is_read;
}				t_file;

#endif