/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyser.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:05:30 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/19 19:24:10 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_ANALYSER_H
# define CORE_ANALYSER_H

# include "expr.h"
# include "label_checker.h"
# include "lexer.h"
# include "parser.h"
# include "token.h"
# include "text.h"
# include "ft_printf.h"


typedef struct s_analyser	t_analyser;









enum					e_analyser_instantiation_status
{
	ANALYSER_INSTANTIATE,
	ANALYSER_DESTRUCT
};

t_analyser				*analyser_singleton_instance(int instatiation_status);
t_vector				*analyse_text(t_analyser *analyser, t_vector *vector,
									t_hash_map *map, char *text);

#endif
