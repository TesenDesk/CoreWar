/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:09:54 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/06 22:27:13 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

enum					e_error_id
{
	EUSAGE,
	ENOMEMORY,
	EINVALARG,
	ENOARGVAL,
	EBADFILENAME,
	ECANNOTCLOSE,
	ECANNOTREAD,
	EINTOUFLOW,
	EREADNOTOPENED,
	EDOUBLEOPENNING,
	EDOUBLECLOSE,
	EMOCKMETHOD,
	ENOPLAYERS,
	EINVALCONSTANTS,
	
	
	
	ERRMSGCOUNT,
};

int				raise(char *file_name, int line_nb, int errmsg_index);

#endif