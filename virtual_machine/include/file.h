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

typedef struct s_file tt_file;


tt_file			*file_new(char *file_name);
void			file_destroy(tt_file **self);
void			*file_data_code(tt_file *self);
char			*file_data_comment(tt_file *self);
char			*file_data_name(tt_file *self);
int				file_player_name(tt_file *self);
int				file_data_check_valid(tt_file *self);

#endif