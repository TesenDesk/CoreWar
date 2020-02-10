/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:58:45 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/10 19:01:39 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "lexer_utils_private.h"

int				lexer_utils_is_line_feed(char c)
{
	int			decision;

	decision = (c == '\n');
	return (decision);
}

int				lexer_utils_is_of_label_chars(char c)
{
	int			decision;

	decision = (ft_strchr(LABEL_CHARS, c) != NULL);
	return (decision);
}

int				lexer_utils_is_label_char(char c)
{
	int			decision;

	decision = (c == LABEL_CHAR);
	return (decision);
}