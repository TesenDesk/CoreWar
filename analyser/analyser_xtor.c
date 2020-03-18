//
// Created by ikira on 13.03.2020.
//

#include "analyser_xtor.h"
#include "analyser_private.h"
#include "text_private.h"



void				_parser_ctor(t_parser **parser) {
	if (!(*parser = (t_parser *) malloc(sizeof(t_parser)))) {
		printf("error\n");
		exit(-1);
	}
	(*parser)->lexer = lexer_singleton_instance(LEXER_INSTANTIATE);
	(*parser)->state = PARSER_INIT_ST;
	(*parser)->change_state = _parser_change_state;
	(*parser)->form_expr = parser_form_expr; //TODO: Не используется через поле структуры. См. parser_private.h
}


void				_analyser_dtor(t_analyser **analyser)
{
	ft_memdel((void **)analyser);
	return ;
}
