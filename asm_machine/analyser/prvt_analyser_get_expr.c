/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_analyser_get_expr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 18:49:10 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/19 19:50:01 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_analyser.h"
#include "expr.h"

t_expr		*prvt_analyser_get_expr(t_vector *label_vector, t_hash_map *map,
									char const **text)
{
	t_parser	*parser;
	t_expr		*expr;

	parser = parser_singleton_instance(PARSER_INSTANTIATE);
	expr = parser_form_expr(parser, text, map, label_vector);
	return (expr);
}
