

#include "analyser_private.h"
#include "analyser_xtor_private.h"
#include "text_private.h"



int					analyse_text(t_analyser *analyser, t_vector *vector,t_hash_map  *map,
		char const **text)
{
	int 			expr_type;
	t_parser		*parser;


	parser = parser_singleton_instance(PARSER_INSTANTIATE);
	while(analyser->state != ANALYSER_FINISH_ST)
	{
		expr_type = analyser->_get_expr(parser, vector, text);
		analyser->_change_state(analyser, expr_type);
		if (analyser->state == ANALYSER_ERROR_ST)
			return (-1);
	}
	return (0);
}




