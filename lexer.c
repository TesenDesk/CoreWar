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

void                lexer_constructor(t_lexer **lexer)
{
	if (!(*lexer = (t_lexer*)malloc(sizeof(t_lexer))))
	{
		printf("error\n");
		exit(-1);
	}
    (*lexer)->state = INIT;
    (*lexer)->change_state = lexer_change_state;
    (*lexer)->lexer_form_token = lexer_form_token;
    (*lexer)->get_term[INIT] = lexer_get_term_init;
    (*lexer)->get_term[COMMENT] = lexer_get_term_comment;
//    (*lexer)->get_term[LINE_FEED] = lexer_get_term_line_feed;
//    (*lexer)->get_term[NAME_CMD] = lexer_get_term_name_cmd;
//    (*lexer)->get_term[CH_NAME] = lexer_get_
//    *lexer->get_term[OPX] = lexer_get_term_opx;
//    *lexer->get_term[ARG_REG] = lexer_get_term_arg_reg;
//    *lexer->get_term[ARG_IND_INT] = lexer_get_term_arg_dir_int;
//    *lexer->get_term[ARG_IND_LABEL] = lexer_get_term_arg_ind_label;
//    *lexer->get_term[ARG_DIR_INT] = lexer_get_term_arg_dir_int;
//    *lexer->get_term[ARG_DIR_LABEL] = lexer_get_term_arg_dir_label;
//    *lexer->get_term[ARG_BREAK] = lexer_get_term_arg_break;
}

void                lexer_destructor(t_lexer **lexer)
{
	free(*lexer);
	*lexer = NULL;
}


static int                  lexer_find_next_to_init(char const **text)
{
    if (**text == COMMENT_CHAR || **text == ALT_COMMENT_CHAR)
        return (COMMENT);
    else if (**text == '\n')
        return (LINE_FEED);
//    else if (strnstr(*text, ".name", 5) || strnstr(*text, ".comment", 8))
//        ;
//    else if (strnstr(*text, ".comment", 8)))
//    return (-1);
    return (1);
}

void                lexer_change_state(t_lexer *lexer, char const **text)
{
    if (lexer->state == INIT)
        lexer->state = lexer_find_next_to_init(text);
//    else
//    {

//    }

}

t_token             *lexer_form_token(t_lexer *lexer, char const **text)
{
    int             token_type;
    void            *token_ptr[2];
    int             token_complete;

    token_type = -1;
    token_ptr[0] = NULL;
    token_ptr[1] = NULL;
    token_complete = 0;
    while (!(token_complete = lexer->get_term[lexer->state](lexer, text, &token_type, token_ptr)))
        lexer_change_state(lexer, text);
    lexer_change_state(lexer, text);
    return (token_constructor(token_type, token_ptr));

}

