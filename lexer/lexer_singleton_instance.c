/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_singleton_instance.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:13:41 by yurezz            #+#    #+#             */
/*   Updated: 2020/02/18 17:27:15 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "lexer_private.h"
#include "lexer_xtor_private.h"

t_lexer				*lexer_singleton_instance()
{
	static t_lexer	*lexer_instance;

	if (!lexer_instance)
		_lexer_constructor(&lexer_instance);
	return (lexer_instance);
}
