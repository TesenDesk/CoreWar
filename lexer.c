/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:39:31 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/15 22:00:43 by cmissy           ###   ########.fr       */
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
    //переделать

    // (*lexer)-> get_term = malloc(20 * sizeof(void *));
    (*lexer)->state = INIT_ST;
    (*lexer)->change_state = lexer_change_state;
    (*lexer)->lexer_form_token = lexer_form_token;
    (*lexer)->get_term[INIT_ST] = lexer_get_term_init;
    (*lexer)->get_term[COMMENT_ST] = lexer_get_term_comment;
    (*lexer)->get_term[LINE_FEED_ST] = lexer_get_term_line_feed;
//    (*lexer)->get_term[LINE_FEED_ST] = lexer_get_term_line_feed;
 //   (*lexer)->get_term[NAME_CMD_ST] = lexer_get_term_name_cmd;
 //   (*lexer)->get_term[CH_NAME_ST] = lexer_get_term_ch_name;
 //   (*lexer)->get_term[COMM_CMD_ST] = lexer_get_term_name_cmd;
 //   (*lexer)->get_term[CH_COMM_ST] = lexer_get_term_ch_name;


// TESTING
    (*lexer)->get_term[OPX_ST] = lexer_get_term_opx;
   (*lexer)->get_term[T_REG_ST] = lexer_get_term_arg_reg;
   (*lexer)->get_term[T_IND_INT_ST] = lexer_get_term_arg_ind_int;
   (*lexer)->get_term[T_IND_LABEL_ST] = lexer_get_term_arg_ind_label;
   (*lexer)->get_term[ARG_BRK_ST] = lexer_get_term_arg_break;
   (*lexer)->get_term[T_DIR_INT_ST] = lexer_get_term_arg_dir_int;
  (*lexer)->get_term[T_DIR_LAB_ST] = lexer_get_term_arg_dir_label   ;
   (*lexer)->get_term[MULTI_ARG_ST] = lexer_get_term_multi_arg;
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


static int                  lexer_find_next_to_INIT_ST(int term_type)
{
    if (term_type == COMMENT_CHAR_CODE || term_type == ALT_COMMENT_CHAR_CODE)
        return (COMMENT_ST);
    else if (term_type == LINE_FEED_CODE)
        return (LINE_FEED_ST);
    else if (term_type == NAME_CMD_STRING_CODE)
        return (NAME_CMD_ST);
    else if (term_type == COMMENT_CMD_STRING_CODE)
        return (COMM_CMD_ST);
    else if (term_type == OPX_CODE)
        return (OPX_ST);
    else
        return (INIT_ST);
}

static int          lexer_find_champ_state(t_lexer *lexer, int term_type)
{

    if (lexer->state == NAME_CMD_ST) {
        if (term_type == QUOTATION_MARK_CODE)
            return (CH_NAME_ST);
    } else if (lexer->state == COMM_CMD_ST) {
        if (term_type == QUOTATION_MARK_CODE)
            return (CH_COMM_ST);
    } else if (lexer->state == CH_NAME_ST || lexer->state == CH_COMM_ST) {
        if (term_type == QUOTATION_MARK_CODE)
            return (INIT_ST);
    }
}

static int          lexer_find_op_arg_state(t_lexer *lexer, int term_type)
{
    if (lexer->state == T_IND_INT_ST)
    {
        if (term_type == SEPARATOR_CHAR_CODE)
            return (MULTI_ARG_ST);
        else if (term_type == WHITE_SPACE_CODE)
            return (INIT_ST);
    }
    else if ((lexer->state == T_REG_ST && term_type == INTEGER_CODE))
            return (ARG_BRK_ST);
    else if ((lexer->state == T_IND_LABEL_ST || lexer->state == T_DIR_LAB_ST)
    && term_type == LABEL_CHARS_CODE)
    {
            return (ARG_BRK_ST);
    }

    else if (lexer->state == T_DIR_INT_ST)
    {
        if (term_type == INTEGER_CODE)
            return (ARG_BRK_ST);
        else if (term_type == LABEL_CHAR_CODE)
            return (T_DIR_LAB_ST);
    }
    else if (lexer->state == ARG_BRK_ST)
    {
        if (term_type == SEPARATOR_CHAR_CODE)
            return (MULTI_ARG_ST);
        else if (term_type == WHITE_SPACE_CODE)
            return (INIT_ST);
    }
    return (INIT_ST);
}

void                lexer_change_state(t_lexer *lexer, int term_type)
{
    if (lexer->state == INIT_ST)
        lexer->state = lexer_find_next_to_INIT_ST(term_type);
    else if (lexer->state >= NAME_CMD_ST && lexer->state <= CH_COMM_ST)
            lexer->state = lexer_find_champ_state(lexer, term_type);
    else if (lexer->state == OPX_ST || lexer->state == MULTI_ARG_ST) {
        if (term_type == REGISTER_CHAR_CODE)
            lexer->state = T_REG_ST;
        else if (term_type == INTEGER_CODE)
            lexer->state = T_IND_INT_ST;
        else if (term_type == LABEL_CHAR_CODE)
            lexer->state = T_IND_LABEL_ST;
        else if (term_type == DIRECT_CHAR_CODE)
            lexer->state = T_DIR_INT_ST;
    }
    else if (lexer->state >= T_REG_ST && lexer->state <= ARG_BRK_ST)
        lexer->state = lexer_find_op_arg_state(lexer, term_type);
    else
        lexer->state = INIT_ST;
}


t_token             *lexer_form_token(t_lexer *lexer, char const **text)
{
    int             token_type;
    void            *token_ptr[2];

    token_type = TOKEN_INIT_ST;
    token_ptr[0] = NULL;
    token_ptr[1] = NULL;
    while (token_type == TOKEN_INIT_ST)
    {
        printf("111  lexer->state%i\n", lexer->state);
        lexer->change_state(lexer, lexer->get_term[lexer->state](lexer, text, &token_type, token_ptr));
    }
    return (token_constructor(token_type, token_ptr));
}

