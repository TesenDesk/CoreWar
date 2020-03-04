#include "parser_private.h"

t_expr				*parser_form_expr(t_parser *parser, char const **text,
					t_hash_map *map, t_vector *vector)
{
	t_expr			*expr;
	int 			expr_type;
	int 			token_type;
	t_lexer 		*lexer;

	/*
	 * лексер есть в парсере
	 */
	lexer = lexer_singleton_instance(LEXER_INSTANTIATE);
	expr = expr_ctor();
	while(TRUE)
	{
		/*
		 * заменить expr_type на expr. там где обрабатываем аргументы операций добавить соответствующие
		 * операции в expr->args (с указанием типа)
		 */
		//token = parser-get
		//if (token_type == LA__WO)
		//if (!//token_check)
		//parser->change_state(parser, token);

		token_type =
			parser->get_token[parser->state](parser, lexer, expr, text);
		if (token_type == TOKEN_LABEL_WORD)
		{
			if (label_checker_put_to_map_label_word(map, expr) ==
					FAILURE)
				return (NULL);
		}
		else if (token_type == TOKEN_TIND_LAB || token_type == TOKEN_TDIR_LAB)
		{
			if (label_checker_put_to_map_label_ptr(vector, expr) == FAILURE)
				return (NULL);
		}
		parser->change_state(parser, token_type);
		if (parser->state == PARSER_INIT_ST)
			break ;
	}
	return (expr);
}




//int     parser_get_token_precode(t_parser *parser)
//{
//    ;
//}
