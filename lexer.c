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

void                lexer_constructor(t_lexer **lexer)
{
	if (!(*lexer = (t_lexer*)malloc(sizeof(t_lexer))))
	{
		printf("error\n");
		exit(-1);
	}
    (*lexer)->state = INIT;
    (*lexer)->lexer_form_token = lexer_form_token;
    (*lexer)->lexer_switcher[COMMENT] = lexer_get_term_comment;
//    (*lexer)->lexer_switcher[LINE_FEED] = lexer_get_term_line_feed;
//    (*lexer)->lexer_switcher[NAME_CMD] = lexer_get_term_name_cmd;
//    (*lexer)->lexer_switcher[CH_NAME] = lexer_get_
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



static int                  lexer_find_init_method(char const *text)
{
    if (*text == COMMENT_CHAR || *text == ALT_COMMENT_CHAR)
        return (COMMENT);
    else if (*text == '\n')
        return (LINE_FEED);
    return (0);
    // else if (strnstr())

}
static int                 lexer_find_method(t_lexer *lexer, char const **text)
{
    if (lexer->state == INIT)
    {
        //переделать
        while (**text == ' ')
            ++(*text);
        return (lexer_find_init_method(*text));
    }
    else if (lexer->state == COMMENT)
        return (COMMENT);
//    else if (lexer->state == line_feed_st)
//        return (LINE_FEED);
//    else if (lexer->state >=name_cmd_st && lexer->state <= ch_comm_st)
//        return (lexer_find_champion_method(text));
//    else if (lexer->state >=opx_name_st && lexer->state <= arg_break_st)
//        return (lexer_find_code_method(text);
    return (0);
}


t_token             *lexer_form_token(t_lexer *lexer, char const **text)
{
    int             token_type;
    void            *token_ptr[2];

    token_type = -1;
    token_ptr[0] = NULL;
    token_ptr[1] = NULL;
    lexer->lexer_switcher[lexer_find_method(lexer, text)](lexer, text, &token_type, token_ptr);
    return (token_constructor(token_type, token_ptr));

}

