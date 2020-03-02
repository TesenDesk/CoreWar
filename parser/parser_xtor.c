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
