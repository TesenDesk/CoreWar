/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_singleton_instance.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:13:41 by yurezz            #+#    #+#             */
/*   Updated: 2020/03/06 21:22:01 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "lexer.h"
#include "lexer_private.h"
#include "lexer_xtor_private.h"

t_lexer				*lexer_singleton_instance(int instantiation_status)
{
	static t_lexer	*lexer_instance;

	if (instantiation_status == LEXER_INSTANTIATE)
	{
		if (!lexer_instance)
			_lexer_ctor(&lexer_instance);
	}
	else if (instantiation_status == LEXER_DESTRUCT)
	{
		if (lexer_instance)
			_lexer_dtor(&lexer_instance);
	}
	return (lexer_instance);
}
