/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:35:16 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/10 20:47:58 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
#define LEXER_H

#include <string.h>
#include "token.h"
#include "token_defines.h"




/*
** The attribute structure with no disclosed attribute.
*/

typedef struct s_lexer          t_lexer;


/*
** Constructor and destructor functions.
*/

void			lexer_constructor(t_lexer **lexer);
void			lexer_destructor(t_lexer **lexer);

/*
** Public behavioral functions.
*/

t_token			*lexer_form_token(t_lexer *lexer, char const **text);

#endif