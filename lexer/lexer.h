/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:35:16 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/18 17:18:39 by yurezz           ###   ########.fr       */
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
**
** __________They are private._________
*/

/*
** Public behavioral functions.
*/
t_lexer         *lexer_singleton_instance(void);
t_token			*lexer_form_token(t_lexer *lexer, char const **text);

#endif