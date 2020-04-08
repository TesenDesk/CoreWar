

#include "analyser_private.h"
#include "analyser_xtor_private.h"
#include "text_private.h"



int					analyse_text(t_analyser *analyser, char const **text)
{
	int 			expr_type;
	t_parser		*parser;


	parser = parser_singleton_instance(PARSER_INSTANTIATE);
	while(TRUE)
	{
		expr_type = analyser->_get_expr[analyser->state](analyser, parser, text);
		analyser->_change_state(analyser, expr_type);
		if (analyser->state == 1)
			return (1);
		else if (analyser->state == -1)
			return (-1);
	}
}




