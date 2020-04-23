/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_singleton_instance.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:37:02 by ftothmur          #+#    #+#             */
/*   Updated: 2020/03/06 21:18:16 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"
#include "parser_xtor_private.h"

t_parser			*parser_singleton_instance(int instantiation_status)
{
	static t_parser	*parser_instance;

//	parser_instance = NULL;

	if (instantiation_status == LEXER_INSTANTIATE)
	{
		if (!parser_instance)
			_parser_ctor(&parser_instance);
	}
	else if (instantiation_status == LEXER_DESTRUCT)
	{
		if (parser_instance)
			_parser_dtor(&parser_instance);
	}
	return (parser_instance);
}
