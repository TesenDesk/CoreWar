/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:12:55 by cmissy            #+#    #+#             */
/*   Updated: 2020/08/16 14:35:06 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "libft.h"
# include "ft_printf.h"
# include "token_defines.h"

enum				e_t_ptr_tips
{
	TOKEN_TEXT_START_INDX = 0,
	TOKEN_TEXT_END_INDX,
};

typedef struct s_token	t_token;

t_token				*token_constructor(int token_type, void *token_ptr[2]);
void				token_destructor(t_token **token);

int					token_get_type(t_token *token);
void				*token_get_token_ptr(t_token *token, int index);
void				*token_get_value(t_token *token);

#endif
