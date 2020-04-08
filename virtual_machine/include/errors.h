/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:09:54 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 04:32:06 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

enum					e_error_id
{
	EUSAGE,
	EINVALARG,	
	ENOMEMORY,
	EBADFILENAME,
	ENOARGVAL,
	ECANNOTCLOSE,
	ECANNOTREAD,
	
	
	
	
	ERRMSGCOUNT,
};

int				raise(char *file_name, int line_nb, int errmsg_index);

#endif