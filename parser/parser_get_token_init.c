

int				parser_get_token_init(t_pareser *parser, ...)
{
	int			token_type;
	token_type = get_token_type(lexer_form_token(lex, &text));
}