/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_get_term_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:30:04 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/19 20:28:32 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_lexer.h"

static int		find_op_type(char const *text)
{
	int			op_code;

	if (((op_code = find_op5_type(text)))
			|| ((op_code = find_op4_type(text)))
			|| ((op_code = find_op3_type(text)))
			|| ((op_code = find_op2_type(text))))
		return (op_code);
	return (0);
}

int				lexer_get_term_init_header(char **text)
{
	if (ft_strnstr(NAME_CMD_STRING, *text, ft_strlen(NAME_CMD_STRING)))
	{
		if (*(*text + ft_strlen(NAME_CMD_STRING)) == ' '
			|| *(*text + ft_strlen(NAME_CMD_STRING)) == '\t')
		{
			(*text) += ft_strlen(NAME_CMD_STRING);
			return (NAME_CMD_STRING_CODE);
		}
	}
	else if (ft_strnstr(COMMENT_CMD_STRING, *text,
					ft_strlen(COMMENT_CMD_STRING)))
	{
		if (*(*text + ft_strlen(COMMENT_CMD_STRING)) == ' '
			|| *(*text + ft_strlen(COMMENT_CMD_STRING)) == '\t')
		{
			(*text) += ft_strlen(COMMENT_CMD_STRING);
			return (COMMENT_CMD_STRING_CODE);
		}
	}
	return (-2);
}

int				lexer_get_term_little_chars(int *type, char **text,
								void *token_ptr[2])
{
	if (!(**text))
	{
		*type = TOKEN_EOF;
		token_ptr[0] = (void*)*text;
		token_ptr[1] = (void*)*text;
		return (EOF_CODE);
	}
	else if (**text == COMMENT_CHAR)
	{
		++(*text);
		return (COMMENT_CHAR_CODE);
	}
	else if (**text == ALT_COMMENT_CHAR)
	{
		++(*text);
		return (ALT_COMMENT_CHAR_CODE);
	}
	else if (**text == LINE_FEED)
	{
		*type = TOKEN_LFEED;
		token_ptr[0] = (void*)*text;
		token_ptr[1] = (void*)(*text)++;
		return (INIT_ST);
	}
	return (-2);
}

int				lexer_get_term_op_label_eof(char **text, int *type,
								void *token_ptr[2])
{
	int			op_len;

	if ((op_len = term_is_op(*text)))
	{
		*type = find_op_type(*text);
		token_ptr[0] = (void*)(*text);
		token_ptr[1] = (void*)(*text + op_len);
		*text += op_len;
		return (OPX_CODE);
	}
	else if (strchr(LABEL_CHARS, **text))
	{
		*token_ptr = (void*)(*text);
		while (strchr(LABEL_CHARS, *(*text)))
			++(*text);
		*(token_ptr + 1) = (void*)(*text - 1);
		return (LABEL_CHARS_CODE);
	}
	else if (**text == TOKEN_EOF)
	{
		*type = TOKEN_EOF;
		return (EOF_CODE);
	}
	return (-2);
}

int				lexer_get_term_init(t_lexer *lexer, char const **text,
									int *type, void *token_ptr[2])
{
	int			stupid_res;

	stupid_res = 0;
	(void)lexer;
	while (**text == ' ' || **text == '\t')
		++(*text);
	if ((stupid_res = lexer_get_term_little_chars(type, (char **)text,
											token_ptr)) != -2)
		return (stupid_res);
	if ((stupid_res = lexer_get_term_init_header((char **)text)) != -2)
		return (stupid_res);
	if ((stupid_res = lexer_get_term_op_label_eof((char **)text, type,
											token_ptr)) != -2)
		return (stupid_res);
	*type = (TOKEN_UNDEF);
	++(*text);
	return (TERM_UNDEFINED_CODE);
}
