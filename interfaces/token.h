/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:12:55 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/14 21:15:17 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "../libft/libft.h"
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
void				*token_get_value(t_token *token);

#endif
