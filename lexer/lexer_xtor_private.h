/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_xtor_private.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:14:25 by yurezz            #+#    #+#             */
/*   Updated: 2020/03/06 19:57:28 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_XTOR_PRIVATE_H
# define LEXER_XTOR_PRIVATE_H

#include "lexer.h"

/*
** Constructor and destructor functions.
*/

void			_lexer_ctor(t_lexer **lexer);
void			_lexer_dtor(t_lexer **lexer);

#endif