#include "parser_private.h"
#include "../lexer/token_defines.h"



void                parser_ctor(t_parser **parser)
{
	if (!(*parser = (t_parser*)malloc(sizeof(t_parser))))
	{
		printf("error\n");
		exit(-1);
	}
	(*parser)->lexer = lexer_singleton_instance(LEXER_INSTANTIATE);
	(*parser)->state = PARSER_INIT_ST;
	(*parser)->_change_state = _parser_change_state;
	(*parser)->form_expr = parser_form_expr;
	(*parser)->get_token[PARSER_INIT_ST] = parser_get_token_init;
//	(*parser)->get_token[PARSER_LINE_END_ST] = parser_get_token_l;
	(*parser)->get_token[PARSER_OP0_AFFECT_ST] = parser_get_token_op_afct;
//	(*parser)->get_token[PARSER_OP0_AFFECT_ST] = parser_get_token_op_afct;
//	(*parser)->get_token[PARSER_OP0_ARITHM_ST] = parser_get_token_op_arit0;
//	(*parser)->get_token[PARSER_OP1_ARITHM_ST] = parser_get_token_op_arit1;
//	(*parser)->get_token[PARSER_OP2_ARITHM_ST] = parser_get_token_op_arit2;
//	(*parser)->get_token[PARSER_OP0_LOAD_ST] = parser_get_token_op_arit2;

//    (*parser)->get_token[PARSER_PRECODE_LINE_ST] = parser_get_token_comment;
//    (*parser)->get_token[PARSER_CODE_COMMENT_ST] = parser_get_token_line_feed;
	/*
	 *
	 *
	 */
//    (*parser)->get_token[LIFE_ST] = parser_get_token_line_feed;

}

void                parser_dtor(t_parser **parser)
{
	free(*parser);
	*parser = NULL;
}
