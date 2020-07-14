/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:33:44 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/13 17:00:01 by cmissy           ###   ########.fr       */
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
	ECANNOTCLOSE,
	ECANNOTREAD,
	EDOUBLEOPENNING,
	EDOUBLECLOSE,
	ENOPLAYERS,
	EINVALCONSTANTS,
	EBADPLAYERNAME,
	EDOUBLENAME,
	EDANGLINGPTR,
	EDATALOSS,
	EWRONGSIZE,
	ENONULLS,
	ENOMAGICH,
	EMANYPLAYERS,
	ERRMSGCOUNT,
};

int				raise(char *file_name, int line_nb, int errmsg_index);

#endif
