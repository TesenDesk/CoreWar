/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:34:08 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/13 12:42:36 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

#include "../src/vm_params/vmp_player/file/prvt_file.h"
typedef struct s_i_file		t_i_file;

t_i_file		*file_new(char *file_name);
void			file_destroy(t_i_file **self);
void			*file_data_code(t_i_file *self);
char			*file_data_comment(t_i_file *self);
char			*file_data_name(t_i_file *self);
int				file_data_check_valid(t_i_file *self);
size_t			file_code_size(t_i_file *self);

#endif
