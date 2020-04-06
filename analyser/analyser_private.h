//
// Created by ikira on 13.03.2020.
//

#ifndef CORE_ANALYSER_PRIVATE_H
#define CORE_ANALYSER_PRIVATE_H

#include "text.h"
#include "parser.h"
#include "analyser.h"

#define ANALYSER_AR_SIZE 20

typedef struct s_analyser t_analyser;
struct s_analyser
{
	int				state;
	t_parser 		*parser;
	t_text*			(*form_text)(t_analyser *analyser,
									char const **text, t_hash_map *map,
									t_vector *vector);
	void			(*_change_state)(t_analyser *analyser, int expr_type);
	/*
	 *сколько состояний?
	 */

	int				(*get_expr[ANALYSER_AR_SIZE])(t_analyser *analyser, t_analyser *analy,
												   t_expr *expr, char const **text);
};

#endif //CORE_ANALYSER_PRIVATE_H
