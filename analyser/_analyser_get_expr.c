//
// Created by ikira on 10.04.2020.
//
#include "analyser_private.h"
#include "expr.h"
#include "../parser/expr_private.h"
//#include "expr.h"

int 			_analyser_get_expr(t_vector *vector, char const ** text, t_hash_map *map)
{

	t_parser 	*parser;
	t_expr		*expr;

	parser = parser_singleton_instance(PARSER_INSTANTIATE);
	expr = parser_form_expr(parser, text, map, vector);
	return expr->type;

}
