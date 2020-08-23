/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_analyser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 18:45:08 by cmissy            #+#    #+#             */
/*   Updated: 2020/08/23 14:59:18 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRVT_ANALYSER_H
# define PRVT_ANALYSER_H

# include "parser.h"
# include "analyser.h"
# include "lexer.h"
# include "expr.h"
# include "token.h"
# include "token_defines.h"

enum			e_analyser_defines
{
	ANALYSER_ERROR_ST = -1,
	ANALYSER_INIT_ST,
	ANALYSER_PRECODE_NAME_ST,
	ANALYSER_PRECODE_COMMENT_ST,
	ANALYSER_CODE_ST,
	ANALYSER_FINISH_ST
};

typedef struct s_analyser	t_analyser;

struct			s_analyser
{
	int			state;

	t_parser	*parser;
	int			(*analyse_text)(t_analyser *analyser, char *text);
	void		(*prvt_change_state)(t_analyser *analyser, int expr_type);
	t_expr		*(*prvt_get_expr)(t_vector *vector, t_hash_map *map,
									char const **text);
};

void			prvt_analyser_change_state(t_analyser *analyser, int expr_type);
t_expr			*prvt_analyser_get_expr(t_vector *label_vector, t_hash_map *map
								, char const **text);

#endif
