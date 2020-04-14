//
// Created by ikira on 13.03.2020.
//

#ifndef CORE_ANALYSER_PRIVATE_H
#define CORE_ANALYSER_PRIVATE_H

//#include "text.h"
#include "parser.h"
#include "analyser.h"
#include "lexer.h"
#include "token.h"
#include "token_defines.h"

#define ANALYSER_AR_SIZE 20



enum 				e_analyser_defines
{
	ANALYSER_ERROR_ST = -1,
	ANALYSER_INIT_ST,
	ANALYSER_PRECODE_NAME_ST,
	ANALYSER_PRECODE_COMMENT_ST,
	ANALYSER_CODE_ST,
	ANALYSER_FINISH_ST
};

typedef struct s_analyser t_analyser;
struct s_analyser
{
	int				state;
	t_parser 		*parser;
	int 			(*analyse_text)(t_analyser *analyser,
								   char const **text);
//	t_expr 			(*analyser_get_expr)(t_analyser *analyser);

	void			(*_change_state)(t_analyser *analyser,  int expr_type);
	int				(*_get_expr)(t_vector *vector,
						char const **text, t_hash_map *map);
	/*
	 *сколько состояний?
	 */

};


void		_analyser_change_state(t_analyser *analyser, int expr_type);
int 		_analyser_get_expr(t_vector *vector, char const ** text, t_hash_map *map);


#endif

