/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:18:37 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 23:15:55 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

typedef struct s_file	t_file;

t_file			*file_new(char *file_name);
void			file_destroy(t_file **self);

#endif
