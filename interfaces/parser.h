/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:10:57 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/14 21:12:00 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "expr.h"
# include "expr_defines.h"

enum							e_parser_instantiation_status
{
	PARSER_INSTANTIATE,
	PARSER_DESTRUCT
};

/*
** The attribute structure with no disclosed attribute.
*/
typedef struct s_parser			t_parser;

/*
** Constructor and destructor functions.
**
** __________They are private.________
** Pass PARSER_INSTANTIATE to construct or to get existatant lexer instance.
** Pass PARSER_DESTRUCT to destrust lexer instance if there is any
*/

t_parser			*parser_singleton_instance(int instantiation_status);

/*
** Public behavioral functions.
*/
int					get_expr_type(t_expr *expr);
t_expr				*parser_form_expr(t_parser *parser, char const **text,
									t_hash_map *map, t_vector *vector);

#endif
