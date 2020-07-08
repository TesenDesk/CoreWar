/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:18:37 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/28 20:22:00 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

typedef struct s_i_file t_i_file;


t_i_file			*file_new(char *file_name);
void			file_destroy(t_i_file **self);
void			*file_data_code(t_i_file *self);
char			*file_data_comment(t_i_file *self);
char			*file_data_name(t_i_file *self);
int				file_data_check_valid(t_i_file *self);
size_t          file_code_size(t_i_file *self);

#endif