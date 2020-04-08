/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _read_data.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:18:37 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 19:50:36 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _READ_DATA_H
# define _READ_DATA_H

# include "libft.h"
# include "errors.h"
# include "read_data.h"

# define INITIAL_CHUNK	128

typedef struct	s_read_data
{
	void		*data;
	ssize_t		total;
	ssize_t		capacity;
	int			is_read;
}				t_read_data;

#endif