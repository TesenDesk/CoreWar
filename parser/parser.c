#include "parser_private.h"
#include "token_private.h"
#include <string.h>
#include <token_private.h>
t_expr				*parser_form_expr(t_parser *parser, char const **text,
					t_hash_map *map, t_vector *label_vector) {
	t_expr *expr;
	t_token		*token;
	int token_type;
	t_lexer *lexer;

	lexer = lexer_singleton_instance(LEXER_INSTANTIATE);
	expr = expr_ctor();
	while (TRUE) {
		token = parser->get_token[parser->state](parser, lexer, expr, text);
		token_type = token_get_type(token);
		if (token_type == TOKEN_LABEL_WORD) {
			if (label_checker_put_to_map_label_word(&map, token) ==
				FAILURE)
				return (NULL);
		} else if (token_type == TOKEN_TIND_LAB || token_type == TOKEN_TDIR_LAB) {
			if (label_checker_put_to_map_label_ptr(label_vector, token) == FAILURE)
				return (NULL);
		}
		parser->change_state(parser, token_type);
		if (parser->state == PARSER_FINISH_ST || parser->state == PARSER_ERROR) {
			if (parser->state == PARSER_ERROR) {
				expr->type = EXPR_UNDEF;
			}
				parser->state = PARSER_INIT_ST;
				break;
		}
	}
	return (expr);
}
