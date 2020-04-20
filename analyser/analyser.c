

#include "analyser_private.h"
#include "analyser_xtor_private.h"
#include "text_private.h"
#include "../parser/expr_private.h"



t_vector		*analyse_text(t_analyser *analyser, t_vector *vector,t_hash_map  *map,
		char const **text)
{
	int 			expr_type;
	t_parser		*parser;
	t_vector		*expr_text;

	expr_type = 0;
	if (!(expr_text = (t_vector*)malloc(sizeof(t_vector))))
			exit(-1);
	if (ft_vector_init(expr_text) == FAILURE)
		exit(-1);
	parser = parser_singleton_instance(PARSER_INSTANTIATE);
	t_expr *expr = NULL;
	while(analyser->state != ANALYSER_FINISH_ST)
	{
		expr = analyser->_get_expr(vector, map, text);
//		printf("bb_type:%d\n", expr->type);
		if (ft_vector_add(expr_text, expr)
			== FAILURE)
			exit(-1);
		expr_type = ((t_expr*)ft_vector_get_curr(expr_text))->type;
//		printf("type:%d\n", expr_type);
		analyser->_change_state(analyser, expr_type);
//		printf("type:%d, state:%d\n", expr_type, analyser->state);
		if (analyser->state == ANALYSER_ERROR_ST)
			exit(-1);
//		if (expr_type == 29)
//			break ;
	}
	return (expr_text);
}




