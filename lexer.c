/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:39:31 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/09 19:51:50 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "lexer_private.h"
#include "token.h"

#define



void                lexer_constructor(t_lexer **lexer)
{
	if (!(*lexer = (t_lexer*)malloc(sizeof(t_lexer))))
	{
		printf("error\n");
		exit(-1);
	}
	*lexer->state = 0;
	*lexer->form_token = lexer_form_token;
	*lexer->lexer_switcher[GET_COMMENT] = lexer_get_term_comment_unit;
    *lexer->lexer_switcher[LINE_FEED] = lexer_get_term_comment_unit;

}

void                lexer_destructor(t_lexer **lexer)
{
	free(*lexer);
	*lexer = NULL;
}

t_token             *lexer_form_token(t_lexer *lexer, char **text)
{
    int             token_type;
    void            *token_begin;
    size_t          token_len;



    lxr_init_term_switch(lexer, text, )



    return (token_constructor(token_type, token_begin, token_len));

}
