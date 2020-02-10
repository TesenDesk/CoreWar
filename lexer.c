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
#include "token_defines.h"

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

#define ADD_NAME				"add"
#define AFF_NAME				"aff"
#define AND_NAME				"and"
#define FORK_NAME				"fork"
#define LD_NAME					"ld"
#define LDI_NAME				"ldi"
#define LFORK_NAME				"lfork"
#define LIVE_NAME				"live"
#define LLD_NAME				"lld"
#define LLDI_NAME				"lldi"
#define OR_NAME					"or"
#define ST_NAME					"st"
#define STI_NAME				"sti"
#define SUB_NAME				"sub"
#define XOR_NAME				"xor"
#define ZJMP_NAME				"zjmp"

//static int                  lexer_op_found(char const **text)
//{
//    //сюда впилить хешмапу, в нее вставить 2 или 3 или 4 или 5 символов текста как ключ. вернуть значение мапы(по этим ключам в мапе 1).
//    return (
//    strnstr(*text, ADD_NAME, 3) || strnstr(*text, AFF_NAME, 3) ||
//    strnstr(*text, AND_NAME, 3) || strnstr(*text, FORK_NAME, 4) ||
//    strnstr(*text, LD_NAME, 2) || strnstr(*text, LDI_NAME, 3) ||
//    strnstr(*text, LFORK_NAME, 5) || strnstr(*text, LIVE_NAME, 4) ||
//    strnstr(*text, LLD_NAME, 3) || strnstr(*text, LLDI_NAME, 4) ||
//    strnstr(*text, OR_NAME, 2) || strnstr(*text, ST_NAME, 2) ||
//    strnstr(*text, STI_NAME, 3) || strnstr(*text, SUB_NAME, 3) ||
//    strnstr(*text, XOR_NAME, 3) || strnstr(*text, ZJMP_NAME, 4)
//    );
//}

//static int                  lexer_find_next_to_com_lf(t_lexer *lexer, char const **text)
//{
//    if (lexer->state == COMMENT)
//    {
//        if (**text == '\n')
//
//    }
//}

//static int                  lexer_find_next_to_init(char const **text)
//{
//    if (**text == COMMENT_CHAR || **text == ALT_COMMENT_CHAR)
//        return (COMMENT);
//    else if (**text == '\n')
//        return (LINE_FEED);
//    else if (strnstr(*text, ".name", 5))
//        return (NAME_CMD);
//    else if (strnstr(*text, ".comment", 8))
//        return (COMM_CMD);
//    else if (lexer_op_found(text))
//        return (OPX);
////    else if (strchr(LABEL_CHARS, **text))
////        return (LA)
//    return (1);
//}

void                lexer_change_state(t_lexer *lexer, int term_type)
{
    if (lexer->state == INIT) {
        ;
//        lexer->state = lexer_find_next_to_init(text);
//        return ;
    }

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
        ;
//        lexer_change_state(lexer, text);
//    lexer_change_state(lexer, text);
    return (token_constructor(token_type, token_ptr));
}

