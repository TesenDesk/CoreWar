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


static int                  lexer_find_next_to_init(int term_type)
{
    if (term_type == COMMENT_CHAR_CODE || term_type == ALT_COMMENT_CHAR_CODE)
        return (COMMENT);
    else if (term_type == LINE_FEED_CODE)
        return (LINE_FEED);
    else if (term_type == NAME_CMD_STRING_CODE)
        return (NAME_CMD);
    else if (term_type == COMMENT_CMD_STRING_CODE)
        return (COMM_CMD);
    else if (term_type >= ADD_NAME_CODE && term_type <= ZJMP_NAME_CODE)
        return (OPX);
}

static int          lexer_find_champ_state(t_lexer *lexer, int term_type)
{

    if (lexer->state == NAME_CMD) {
        if (term_type == QUOTATION_MARK_CODE)
            return (CH_NAME);
    } else if (lexer->state == COMM_CMD) {
        if (term_type == QUOTATION_MARK_CODE)
            return (CH_COMM);
    } else if (lexer->state == CH_NAME || lexer->state == CH_COMM) {
        if (term_type == QUOTATION_MARK_CODE)
            return (INIT);
    }
}

static int          lexer_find_op_arg_state(t_lexer *lexer, int term_type)
{
    if (lexer->state == T_IND_INT)
    {
        if (term_type == SEPARATOR_CHAR_CODE)
            return (MULTI_ARG);
        else if (term_type == WHITE_SPACE_CODE)
            return (INIT);
    }
    else if ((lexer->state == T_REG && term_type == INTEGER_CODE))
            return (ARG_BRK);
    else if ((lexer->state == T_IND_LABEL || lexer->state == T_DIR_LAB)
    && term_type == LABEL_CHARS_CODE)
            return (ARG_BRK);
    else if (lexer->state == T_DIR_INT)
    {
        if (term_type == INTEGER_CODE)
            return (ARG_BRK);
        else if (term_type == LABEL_CHAR_CODE)
            return (T_DIR_LAB);
    }
}

void                lexer_change_state(t_lexer *lexer, int term_type)
{
    if (lexer->state == INIT)
        lexer->state = lexer_find_next_to_init(term_type);
    else if (lexer->state >= NAME_CMD && lexer->state <= CH_COMM)
            lexer->state = lexer_find_champ_state(lexer, term_type);
    else if (lexer->state == OPX) {
        if (term_type == REGISTER_CHAR_CODE)
            lexer->state = T_REG;
        else if (term_type == INTEGER_CODE)
            lexer->state = T_IND_INT;
        else if (term_type == LABEL_CHAR_CODE)
            lexer->state = T_IND_LABEL;
        else if (term_type == DIRECT_CHAR_CODE)
            lexer->state = T_DIR_INT;
    }
    else if (lexer->state >= T_REG && lexer->state <= ARG_BRK)
        lexer->state = lexer_find_op_arg_state(lexer, term_type);

}


t_token             *lexer_form_token(t_lexer *lexer, char const **text)
{
    int             token_type;
    void            *token_ptr[2];

    token_type = TOKEN_INIT;
    token_ptr[0] = NULL;
    token_ptr[1] = NULL;
    while (token_type == TOKEN_INIT) {
        printf("1111\n");
        lexer->change_state(lexer, lexer->get_term[lexer->state](lexer, text, &token_type, token_ptr));
    }
    return (token_constructor(token_type, token_ptr));
}

