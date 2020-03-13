//
// Created by ikira on 13.03.2020.
//

#ifndef CORE_ANALYSER_PRIVATE_H
#define CORE_ANALYSER_PRIVATE_H

#include <analyser.h>
#include <text.h>

#define ANALYSER_AR_SIZE 20

typedef struct		s_analyser
{
	int				state;
	t_text*			(*form_text)(struct s_analyser *analyser,
									char const **text, t_hash_map *map,
									t_vector *vector);
	void			(*_change_state)(struct s_analyser *analyser, int expr_type);
	/*
	 *сколько состояний?
	 */

	int				(*get_expr[ANALYSER_AR_SIZE])(struct s_analyser *analyser, t_analyser *analyser,
												   t_expr *expr, char const **text);
}					t_analyser;

#endif //CORE_ANALYSER_PRIVATE_H
