/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_xtor_private.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:39:41 by ftothmur          #+#    #+#             */
/*   Updated: 2020/07/15 16:24:53 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_XTOR_PRIVATE_H
# define PARSER_XTOR_PRIVATE_H


# include "parser.h"

/*
** Constructor and destructor functions.
*/

void			prvt_parser_ctor(t_parser **parser);
void			prvt_parser_dtor(t_parser **parser);

#endif
