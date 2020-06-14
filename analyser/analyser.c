

#include "analyser_private.h"
#include "analyser_xtor_private.h"
#include "text_private.h"
#include "../parser/expr_private.h"



t_vector		*analyse_text(t_analyser *analyser, t_vector *vector,t_hash_map  *map,
		char const **text)
{
	int 			expr_type;
	t_vector		*expr_text;
	t_expr			*expr;

	expr_type = 0;
	expr = NULL;
	if (!(expr_text = (t_vector*)malloc(sizeof(t_vector))))
			exit(-1);
	if (ft_vector_init(expr_text) == FAILURE)
		exit(-1);
	while(analyser->state != ANALYSER_FINISH_ST)
	{
		expr = analyser->_get_expr(vector, map, text);
		if (ft_vector_add(expr_text, expr)
			== FAILURE)
			exit(-1);
		expr_type = ((t_expr*)ft_vector_get_curr(expr_text))->type;
		analyser->_change_state(analyser, expr_type);
//		printf("type:%d, state:%d\n", expr_type, analyser->state);
		if (analyser->state == ANALYSER_ERROR_ST)
			exit(-1);
	}
	return (expr_text);
}




