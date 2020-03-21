/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_xtor_private.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:40:45 by yurezz            #+#    #+#             */
/*   Updated: 2020/03/21 03:08:02 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "lexer_private.h"
#include "lexer_xtor_private.h"

void			_lexer_ctor(t_lexer **lexer)
{
	if (!(*lexer = (t_lexer*)malloc(sizeof(t_lexer))))
	{
		("error\n");
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
   (*lexer)->get_term[NAME_CMD_ST] = lexer_get_term_name_cmd;
   (*lexer)->get_term[CH_NAME_ST] = lexer_get_term_ch_name;
   (*lexer)->get_term[COMM_CMD_ST] = lexer_get_term_name_cmd;
   (*lexer)->get_term[CH_COMM_ST] = lexer_get_term_ch_comment;


// TESTING
	(*lexer)->get_term[OPX_ST] = lexer_get_term_opx;
   (*lexer)->get_term[T_REG_ST] = lexer_get_term_arg_reg;
   (*lexer)->get_term[T_IND_INT_ST] = lexer_get_term_arg_ind_int;
   (*lexer)->get_term[T_IND_LABEL_ST] = lexer_get_term_arg_ind_label;
   (*lexer)->get_term[ARG_BRK_ST] = lexer_get_term_arg_break;
   (*lexer)->get_term[T_DIR_INT_ST] = lexer_get_term_arg_dir_int;
  (*lexer)->get_term[T_DIR_LAB_ST] = lexer_get_term_arg_dir_label;
   (*lexer)->get_term[MULTI_ARG_ST] = lexer_get_term_multi_arg;
   (*lexer)->get_term[LABEL_WORD_ST] = lexer_get_term_label_word_unit;
}

void			_lexer_dtor(t_lexer **lexer)
{
	free(*lexer);
	*lexer = NULL;
}