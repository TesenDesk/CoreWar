/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:18:37 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/26 03:28:27 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

typedef struct s_file	t_file;

// t_file			*file_new(char *file_name);
t_file			*file_new(int player_name, char *file_name);
void			file_destroy(t_file **self);
void			*file_data_code(t_file *self);
char			*file_data_comment(t_file *self);
char			*file_data_name(t_file *self);
int				file_player_name(t_file *self);
int				file_data_precondition_check(t_file *self);


#endif