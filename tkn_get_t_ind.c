int		lexer_get_t_ind_integer(t_lexer *lexer, char const **text, int *token_type, void *token_ptr[2])
{
	void	*t;

	t = (void*)lexer;
	token_ptr[0] = *text;
	if (**text == '+' || **text == '-')
	{
		++(*text);
		if (!ft_isdigit(**text))
		{
			token_type = UNDEFINED_TOKEN;
			return (1);
		}
	}
	token_type = T_IND_INT;
	while (ft_isdig(**text))
		++(*text);
	token_ptr[1] = *text - 1;
	return (INTEGER_CODE);
}

int		lexer_get_t_ind_label(t_lexer *lexer, char const **text,
		int *token_type, void *token_ptr[2])
{
	void	*t;

	t = (void*)lexer;
	token_ptr[0] = *text;
	++(*text);
	if (!ft_strchr(LABEL_CHARS, **text))
		*token_type = UNDEFINED_TOKEN;
	else
	{
		token_type = T_IND_LABEL;
		while (ft_strchr(LABEL_CHARS, **text))
			++(*text);
		token_ptr[1] = *text - 1;
	}
	return (LABEL_CHARS_CODE);
}

int			tkn_get_break(t_lexer *lexer, char const **text,
			int *token_type, void *token_ptr[2])
{
	if (ft_strchr(WHITE_SPACE, **text))
		return ();
	if (**text == SEPARATOR_CHAR)
		return ();
	if (**text == '\n')
		return ();
}