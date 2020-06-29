/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:44:55 by ftothmur          #+#    #+#             */
/*   Updated: 2020/03/06 20:42:31 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_PRIVATE_H
#define TOKEN_PRIVATE_H

#include "token.h"
#include "token_defines.h"

//#define UNDEF_TOKEN -1

typedef struct		s_token
{
	int				type;
	void			*val;
	void			*token_ptr[2];
	int				(*get_type)(t_token  *token);
	void			*(*get_begin)(t_token *token);
	void			*(*get_val)(t_token *token);
}					t_token;

#endif