/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:35:16 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/23 14:47:34 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "token.h"
# include "ft_printf.h"

enum					e_lexer_instantiation_status
{
	LEXER_INSTANTIATE,
	LEXER_DESTRUCT
};

/*
** The attribute structure with no disclosed attribute.
*/

typedef struct s_lexer	t_lexer;

/*
** Constructor and destructor functions.
**
** __________They are private._________
** Pass LEXER_INSTANTIATE to construct or to get existatant lexer instance.
** Pass LEXER_DESTRUCT to destrust lexer instance if there is any.
*/

t_lexer					*lexer_singleton_instance(int instantiation_status);

/*
** Public behavioral functions.
*/

t_token					*lexer_form_token(t_lexer *lexer, char const **text);

#endif
