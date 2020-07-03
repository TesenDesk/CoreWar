/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_file.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:18:37 by yurezz            #+#    #+#             */
/*   Updated: 2020/07/01 18:18:05 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRVT_FILE_H
# define PRVT_FILE_H

# include "libft.h"
# include "errors.h"
# include "file.h"
# include "op.h"

# define MAGIC_LENGTH		4
# define NULL_LENGTH		4
# define CHAMP_SIZE_LENGTH	4

# define INITIAL_CHUNK		128

typedef struct				s_i_file
{
	void					*data;
	unsigned int			total;
	unsigned int			capacity;
	char					*file_name;
	int						fd;
	int						is_opened;
	int						is_read;
}							t_i_file;

void						prvt_file_read(tt_file *self);
void						prvt_file_open(tt_file *self);
void						prvt_file_close(tt_file *self);
void						prvt_file_allocate_intitial_value(tt_file *self);
void						prvt_file_reallocate_value(tt_file *self);

#endif
