// #include "token_defines.h"
#include "lexer_private.h"
// #include "lexer.h"

static int			term_is_op(char const *text)
{
	char		*cmds_arr[16] = {
		LFORK_NAME, FORK_NAME, LIVE_NAME, LLDI_NAME, ZJMP_NAME, ADD_NAME,
		AFF_NAME, AND_NAME, LDI_NAME, LLD_NAME, STI_NAME, SUB_NAME, XOR_NAME,
		LD_NAME, OR_NAME, ST_NAME,
	};
	int			i;
	int			len;

	i = 0;
	while (i < 16)
	{
		len = ft_strlen(cmds_arr[i]);
		if (ft_strnstr(text, cmds_arr[i], len - 1))
			if (text[len - 1] == ' ' || text[len - 1] == '\t')
				return (len);
		i++;
	}
	return (0);
}

// static int      term_is_op(char const *text)
// {
//     if (ft_strnstr(text, LFORK_NAME, 5))
//     	return (5);
//     else if (ft_strnstr(text, FORK_NAME, 4) || ft_strnstr(text, LIVE_NAME, 4)
//              || ft_strnstr(text, LLDI_NAME, 4) || ft_strnstr(text, ZJMP_NAME, 4))
// 	    return (4);
//     else if (ft_strnstr(text, ADD_NAME, 3) || ft_strnstr(text, AFF_NAME, 3)
//              || ft_strnstr(text, AND_NAME, 3) || ft_strnstr(text, LDI_NAME, 3)
//              || ft_strnstr(text, LLD_NAME, 3) || ft_strnstr(text, STI_NAME, 3)
//              || ft_strnstr(text, SUB_NAME, 3) || ft_strnstr(text, XOR_NAME, 3))
// 	    return (3);
// 	else if (ft_strnstr(text, LD_NAME, 2) || ft_strnstr(text, OR_NAME, 2)
// 	    || ft_strnstr(text, ST_NAME, 2))
// 		return (2);
// 	return (0);
// }

static int		find_op2_type(char const *text)
{
	if (ft_strnstr(text, LD_NAME, ft_strlen(LD_NAME)))
		return (TOKEN_LD);
	else if (ft_strnstr(text, OR_NAME, ft_strlen(OR_NAME)))
		return (TOKEN_OR);
	else if (ft_strnstr(text, ST_NAME, ft_strlen(ST_NAME)))
		return (TOKEN_ST);
	return (0);
}

static int      find_op3_type(char const *text)
{
	if (ft_strnstr(text, ADD_NAME, ft_strlen(ADD_NAME)))
		return (TOKEN_ADD);
	else if (ft_strnstr(text, AFF_NAME, ft_strlen(AFF_NAME)))
		return (TOKEN_AFF);
	else if (ft_strnstr(text, AND_NAME, ft_strlen(AND_NAME)))
		return (TOKEN_AND);
	else if (ft_strnstr(text, LDI_NAME, ft_strlen(LDI_NAME)))
		return (TOKEN_LDI);
	else if (ft_strnstr(text, LLD_NAME, ft_strlen(LLD_NAME)))
		return (TOKEN_LLD);
	else if (ft_strnstr(text, STI_NAME, ft_strlen(STI_NAME)))
		return (TOKEN_STI);
	else if (ft_strnstr(text, SUB_NAME, ft_strlen(SUB_NAME)))
		return (TOKEN_SUB);
	else if (ft_strnstr(text, XOR_NAME, ft_strlen(XOR_NAME)))
		return (TOKEN_XOR);
	return (0);
}

static int		find_op4_type(char const *text)
{
	if (ft_strnstr(text, FORK_NAME, ft_strlen(FORK_NAME)))
		return (TOKEN_FORK);
	else if (ft_strnstr(text, LIVE_NAME, ft_strlen(LIVE_NAME)))
		return (TOKEN_LIVE);
	else if (ft_strnstr(text, LLDI_NAME, ft_strlen(LLDI_NAME)))
		return (TOKEN_LLDI);
	else if (ft_strnstr(text, ZJMP_NAME, ft_strlen(ZJMP_NAME)))
		return(TOKEN_ZJMP);
	return (0);
}

static int		find_op5_type(char const *text)
{
	if (ft_strnstr(text, LFORK_NAME, ft_strlen(LFORK_NAME)))
		return (TOKEN_LFORK);
	return (0);
}


static int      find_op_type(char const *text)
{
	int         op_code;

	op_code = 0;
	if ((op_code = find_op5_type(text)) || (op_code = find_op4_type(text))
	|| (op_code = find_op3_type(text)) || (op_code = find_op2_type(text)))
		;
	return (op_code);
}


int             lexer_get_term_init(t_lexer *lexer, char const **text, int *type, void *token_ptr[2])
{
	int op_len;

	op_len = 0;
	while (**text == ' ' || **text == '\t')
		++(*text);
	if (!(**text))
	{
		*type = TOKEN_EOF;
		return (EOF_CODE);
	}
	else if (**text == COMMENT_CHAR) {
		++(*text);
		return (COMMENT_CHAR_CODE);
	}
	else if (**text == ALT_COMMENT_CHAR) {
		++(*text);
		return (ALT_COMMENT_CHAR_CODE);
	}
	else if (**text == LINE_FEED) {
		*type = TOKEN_LFEED;
		++(*text);
		return (INIT_ST);
	}
	else if (ft_strnstr(*text, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING))) {
		(*text) += ft_strlen(NAME_CMD_STRING);
		return (NAME_CMD_STRING_CODE);
	}
	else if (ft_strnstr(*text, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING))){
		(*text) += ft_strlen(COMMENT_CMD_STRING);
		return (COMMENT_CMD_STRING_CODE);
	}
	else if ((op_len = term_is_op(*text)))
	{
		*type = find_op_type(*text);
		*token_ptr = (void*)(*text);
		*(token_ptr + 1) =  (void*)(*(text + op_len));
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
	*type = (TOKEN_UNDEF);
	++(*text);
	return (TERM_UNDEFINED_CODE);
}
