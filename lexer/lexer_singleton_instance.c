/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_singleton_instance.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:13:41 by yurezz            #+#    #+#             */
/*   Updated: 2020/07/15 12:47:37 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_lexer.h"
#include "prvt_lexer_xtor.h"

t_lexer				*lexer_singleton_instance(int instantiation_status)
{
	static t_lexer	*lexer_instance;

	if (instantiation_status == LEXER_INSTANTIATE)
	{
		if (!lexer_instance)
			prvt_lexer_ctor(&lexer_instance);
	}
	else if (instantiation_status == LEXER_DESTRUCT)
	{
		if (lexer_instance)
			prvt_lexer_dtor(&lexer_instance);
	}
	return (lexer_instance);
}
