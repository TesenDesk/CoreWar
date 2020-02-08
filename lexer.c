/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:39:31 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/04 18:29:53 by ftothmur         ###   ########.fr       */
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
	*lexer->lexer_switcher[GET_COMMENT] = lexer_get_term_comment;
    *lexer->lexer_switcher[LINE_FEED] = lexer_get_term_line_feed;
    *lexer->lexer_switcher[CHAMPION] = lexer_get_term_champion;
//    *lexer->lexer_switcher[OPX] = lexer_get_term_opx;
//    *lexer->lexer_switcher[ARG_REG] = lexer_get_term_arg_reg;
//    *lexer->lexer_switcher[ARG_IND_INT] = lexer_get_term_arg_dir_int;
//    *lexer->lexer_switcher[ARG_IND_LABEL] = lexer_get_term_arg_ind_label;
//    *lexer->lexer_switcher[ARG_DIR_INT] = lexer_get_term_arg_dir_int;
//    *lexer->lexer_switcher[ARG_DIR_LABEL] = lexer_get_term_arg_dir_label;
//    *lexer->lexer_switcher[ARG_BREAK] = lexer_get_term_arg_break;
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



    return (token_constructor(token_type, token_begin, token_len));

}
