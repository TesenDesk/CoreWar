//
// Created by ikira on 13.03.2020.
//

#ifndef CORE_ANALYSER_H
#define CORE_ANALYSER_H

#include "_expr.h"
#include "expr_defines.h"
#include "label_checker.h"
#include "lexer.h"
#include "parser.h"
#include "token.h"
#include "token_defines.h"
#include "text.h"

typedef struct s_analyser t_analyser;


enum					e_analyser_instantiation_status
{
	ANALYSER_INSTANTIATE,
	ANALYSER_DESTRUCT
};

t_analyser *analyser_singleton_instance(int instatiation_status);

t_vector 			*analyse_text(t_analyser *analyser, t_vector *vector,
							   t_hash_map  *map, char *text);

#endif //CORE_ANALYSER_H
