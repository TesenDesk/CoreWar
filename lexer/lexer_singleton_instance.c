/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_singleton_instance.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:13:41 by yurezz            #+#    #+#             */
/*   Updated: 2020/03/20 21:50:58 by nikita_toro      ###   ########.fr       */
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
		lexer_instance = NULL;
		if (!lexer_instance)
			_lexer_ctor(&lexer_instance); // обращение к lexer_instance до инициализации
	}
	else if (instantiation_status == LEXER_DESTRUCT)
	{
		if (lexer_instance)
			_lexer_dtor(&lexer_instance);
	}
	return (lexer_instance);
}
