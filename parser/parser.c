#include "parser_private.h"







t_expr             *parser_form_expr(t_parser  *parser,  char const **text)
{
	t_expr			*expr;
	int 			expr_type;
	t_lexer 		*lexer;

	/*
	 * лексер есть в парсере
	 */
	lexer = lexer_singleton_instance(LEXER_INSTANTIATE);
	expr = expr_ctor();
	while(1)
	{
		/*
		 * заменить expr_type на expr. там где обрабатываем аргументы операций добавить соответствующие
		 * операции в expr->args (с указанием типа)
		 */
		//token = parser-get
		//if (token_type == LA__WO)
		//if (!//token_check)
		//parser->change_state(parser, token);

		parser->_change_state(parser, parser->get_token[parser->state](parser, lexer, expr, text));
		if (parser->state == PARSER_INIT_ST)
			break ;
	}
	return (expr);
}




//int     parser_get_token_precode(t_parser *parser)
//{
//    ;
//}
