/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_xtor_private.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:14:25 by yurezz            #+#    #+#             */
/*   Updated: 2020/02/18 17:26:48 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_XTOR_PRIVATE_H
# define LEXER_XTOR_PRIVATE_H

/*
** Constructor and destructor functions.
*/

void			lexer_ctor(t_lexer **lexer);
void			lexer_dtor(t_lexer **lexer);

#endif