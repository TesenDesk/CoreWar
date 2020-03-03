#include "parser_private.h"



void                parser_ctor(t_parser **parser)
{
	if (!(*parser = (t_parser*)malloc(sizeof(t_parser))))
	{
		printf("error\n");
		exit(-1);
	}
	(*parser)->lexer = lexer_singleton_instance(LEXER_INSTANTIATE);
	(*parser)->state = PARSER_INIT_ST;
	(*parser)->change_state = _parser_change_state;
	(*parser)->form_expr = parser_form_expr;
	(*parser)->get_token[PARSER_INIT_ST] = _parser_get_token_init;
	// (*parser)->get_token[PARSER_PRECODE_LINE_ST] = parser_get_token_l;
	// (*parser)->get_token[PARSER_CODE_COMMENT_ST] = parser_get_token_op_afct;
	// (*parser)->get_token[PARSER_LIFE_ST] = parser_get_token_op_afct;
	(*parser)->get_token[PARSER_OP0_LIFE_ST] = _parser_get_token_op_life;
	(*parser)->get_token[PARSER_OP0_AFFECT_ST] = _parser_get_token_op_afct;
	(*parser)->get_token[PARSER_OP0_LOAD_ST] = _parser_get_token_op0_load;
	(*parser)->get_token[PARSER_OP1_LOAD_ST] = _parser_get_token_op1_load;
	(*parser)->get_token[PARSER_OP0_STORE_ST] = _parser_get_token_op0_stor;
	(*parser)->get_token[PARSER_OP1_STORE_ST] = _parser_get_token_op1_stor;
	(*parser)->get_token[PARSER_OP0_ARITHM_ST] = _parser_get_token_op0_arit;
	(*parser)->get_token[PARSER_OP1_ARITHM_ST] = _parser_get_token_op1_arit;
	(*parser)->get_token[PARSER_OP2_ARITHM_ST] = _parser_get_token_op2_arit;
	(*parser)->get_token[PARSER_OP0_LOADI_ST] = _parser_get_token_op0_lodi;
	(*parser)->get_token[PARSER_OP1_LOADI_ST] = _parser_get_token_op1_lodi;
	(*parser)->get_token[PARSER_OP2_LOADI_ST] = _parser_get_token_op2_lodi;
	(*parser)->get_token[PARSER_OP0_LOGIC_ST] = _parser_get_token_op0_logc;
	(*parser)->get_token[PARSER_OP1_LOGIC_ST] = _parser_get_token_op1_logc;
	(*parser)->get_token[PARSER_OP2_LOGIC_ST] = _parser_get_token_op2_logc;
	(*parser)->get_token[PARSER_OP0_STORI_ST] = _parser_get_token_op0_stri;
	(*parser)->get_token[PARSER_OP1_STORI_ST] = _parser_get_token_op1_stri;
	(*parser)->get_token[PARSER_OP2_STORI_ST] = _parser_get_token_op2_stri;
	(*parser)->get_token[PARSER_LINE_END_ST] = _parser_get_token_line_end;

	/*
	 *
	 *
	 */
//    (*parser)->get_token[LIFE_ST] = parser_get_token_line_feed;

}

void                parser_dtor(t_parser **parser)
{
	// free(*parser);
	// *parser = NULL;
	ft_memdel(parser);
	return ;
}
