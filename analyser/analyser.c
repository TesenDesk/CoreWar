

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
		if (ft_vector_add(expr_text, expr)
			== FAILURE)
			exit(-1);
		printf("tot:%d\n", expr_text->total);
		if (expr_text->total > 1)
		{
			int i = 0;
			while (i < expr_text->total) {
				t_expr *tmp = ((t_expr *) (expr_text)->items + i++);
				printf("%d, %s\n", tmp->type, tmp->name);
			}
		}
		expr_type = ((t_expr*)ft_vector_get_curr(expr_text))->type;
		analyser->_change_state(analyser, expr_type);
		if (analyser->state == ANALYSER_ERROR_ST)
			exit(-1);
	}
	return (expr_text);
}




