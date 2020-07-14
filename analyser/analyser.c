/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 18:28:06 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/14 18:28:06 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_analyser.h"
#include "../parser/expr_private.h"

t_vector		*analyse_text(t_analyser *analyser, t_vector *vector,
								t_hash_map *map, char *text)
{
	int			expr_type;
	t_vector	*expr_text;
	t_expr		*expr;

	expr_type = 0;
	expr = NULL;
	if (!(expr_text = (t_vector*)malloc(sizeof(t_vector))))
		exit(-1);
	if (ft_vector_init(expr_text) == FAILURE)
		exit(-1);
	while (analyser->state != ANALYSER_FINISH_ST)
	{
		expr = analyser->prvt_get_expr(vector, map, (((char const**)&text)));
		if (ft_vector_add(expr_text, expr) == FAILURE)
			exit(-1);
		expr_type = ((t_expr*)ft_vector_get_curr(expr_text))->type;
		analyser->prvt_change_state(analyser, expr_type);
		if (analyser->state == ANALYSER_ERROR_ST)
			exit(-1);
	}
	return (expr_text);
}
