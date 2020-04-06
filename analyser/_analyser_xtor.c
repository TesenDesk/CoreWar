//
// Created by ikira on 13.03.2020.
//

#include "analyser_xtor_private.h"
#include "analyser_private.h"
#include "text_private.h"



t_analyser 			_analyser_ctor(t_analyser **analyser) {
	if (!(*analyser = (t_analyser *) malloc(sizeof(t_analyser)))) {
		printf("error\n");
		exit(-1);
	}
	(*analyser)->parser = parser_singleton_instance(PARSER_INSTANTIATE);
	(*analyser)->state = PARSER_INIT_ST;
	(*analyser)->change_state = _analyser_change_state;
}


void				_analyser_dtor(t_analyser **analyser)
{
	(*analyser)->parser = parser_singleton_instance(PARSER_DESTRUCT)
	ft_memdel((void **)analyser);
	return ;
}
