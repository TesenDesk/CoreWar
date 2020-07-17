/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parser_xtor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:42:19 by ftothmur          #+#    #+#             */
/*   Updated: 2020/07/17 16:22:49 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

void				prvt_parser_ctor_p2(t_parser **parser)
{
	(*parser)->get_token[PARSER_OP2_ARITHM_ST] = prvt_parser_get_token_op2_arit;
	(*parser)->get_token[PARSER_OP0_LOADI_ST] = prvt_parser_get_token_op0_lodi;
	(*parser)->get_token[PARSER_OP1_LOADI_ST] = prvt_parser_get_token_op1_lodi;
	(*parser)->get_token[PARSER_OP2_LOADI_ST] = prvt_parser_get_token_op2_lodi;
	(*parser)->get_token[PARSER_OP0_LOGIC_ST] = prvt_parser_get_token_op0_logc;
	(*parser)->get_token[PARSER_OP1_LOGIC_ST] = prvt_parser_get_token_op1_logc;
	(*parser)->get_token[PARSER_OP2_LOGIC_ST] = prvt_parser_get_token_op2_logc;
	(*parser)->get_token[PARSER_OP0_STORI_ST] = prvt_parser_get_token_op0_stri;
	(*parser)->get_token[PARSER_OP1_STORI_ST] = prvt_parser_get_token_op1_stri;
	(*parser)->get_token[PARSER_OP2_STORI_ST] = prvt_parser_get_token_op2_stri;
	(*parser)->get_token[PARSER_LINE_END_ST] = prvt_parser_get_token_line_end;
}

void				prvt_parser_ctor(t_parser **parser)
{
	if (!(*parser = (t_parser*)malloc(sizeof(t_parser))))
	{
		printf("error\n");
		exit(-1);
	}
	(*parser)->lexer = lexer_singleton_instance(LEXER_INSTANTIATE);
	(*parser)->state = PARSER_INIT_ST;
	(*parser)->change_state = prvt_parser_change_state;
	(*parser)->form_expr = parser_form_expr;
	(*parser)->get_token[PARSER_INIT_ST] = prvt_parser_get_token_init;
	(*parser)->get_token[PARSER_OP0_LIFE_ST] = prvt_parser_get_token_op0_life;
	(*parser)->get_token[PARSER_OP0_AFFECT_ST] = prvt_parser_get_token_op0_afct;
	(*parser)->get_token[PARSER_OP0_LOAD_ST] = prvt_parser_get_token_op0_load;
	(*parser)->get_token[PARSER_OP1_LOAD_ST] = prvt_parser_get_token_op1_load;
	(*parser)->get_token[PARSER_OP0_STORE_ST] = prvt_parser_get_token_op0_stor;
	(*parser)->get_token[PARSER_OP1_STORE_ST] = prvt_parser_get_token_op1_stor;
	(*parser)->get_token[PARSER_OP0_ARITHM_ST] = prvt_parser_get_token_op0_arit;
	(*parser)->get_token[PARSER_OP1_ARITHM_ST] = prvt_parser_get_token_op1_arit;
	prvt_parser_ctor_p2(parser);
}

void				prvt_parser_dtor(t_parser **parser)
{
	ft_memdel((void **)parser);
	return ;
}
