/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_xtor_private.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:39:41 by ftothmur          #+#    #+#             */
/*   Updated: 2020/03/06 21:17:39 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_XTOR_PRIVATE_H
# define PARSER_XTOR_PRIVATE_H

#include "parser.h"

/*
** Constructor and destructor functions.
*/

void			_parser_ctor(t_parser **parser);
void			_parser_dtor(t_parser **parser);

#endif