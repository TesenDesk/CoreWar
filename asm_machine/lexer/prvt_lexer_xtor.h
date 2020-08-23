/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_lexer_xtor.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:14:25 by yurezz            #+#    #+#             */
/*   Updated: 2020/08/23 14:55:48 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRVT_LEXER_XTOR_H
# define PRVT_LEXER_XTOR_H

# include "lexer.h"

/*
** Constructor and destructor functions.
*/

void			prvt_lexer_ctor(t_lexer **lexer);
void			prvt_lexer_dtor(t_lexer **lexer);

#endif
