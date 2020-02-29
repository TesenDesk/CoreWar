#include "token_defines.h"
#include "lexer_private.h"

static int      term_is_op(char const *text)
{
    if (ft_strnstr(text, LFORK_NAME, 5))
    	return (5);
    else if (ft_strnstr(text, FORK_NAME, 4) || ft_strnstr(text, LIVE_NAME, 4)
             || ft_strnstr(text, LLDI_NAME, 4) || ft_strnstr(text, ZJMP_NAME, 4))
	    return (4);
    else if (ft_strnstr(text, ADD_NAME, 3) || ft_strnstr(text, AFF_NAME, 3)
             || ft_strnstr(text, AND_NAME, 3) || ft_strnstr(text, LDI_NAME, 3)
             || ft_strnstr(text, LLD_NAME, 3) || ft_strnstr(text, STI_NAME, 3)
             || ft_strnstr(text, SUB_NAME, 3) || ft_strnstr(text, XOR_NAME, 3))
	    return (3);
	else if (ft_strnstr(text, LD_NAME, 2) || ft_strnstr(text, OR_NAME, 2)
	    || ft_strnstr(text, ST_NAME, 2))
		return (2);
	return (0);
}

static int      find_op2_type(char const *text)
{
	if (ft_strnstr(text, LD_NAME, 2))
		return (TOKEN_LD);
	else if (ft_strnstr(text, OR_NAME, 2))
		return (TOKEN_OR);
	else if (ft_strnstr(text, ST_NAME, 2))
		return (TOKEN_ST);
	return (0);
}

static int      find_op3_type(char const *text)
{
	if (ft_strnstr(text, ADD_NAME, 3))
		return (TOKEN_ADD);
	else if (ft_strnstr(text, AFF_NAME, 3))
		return (TOKEN_AFF);
	else if (ft_strnstr(text, AND_NAME, 3))
		return (TOKEN_AND);
	else if (ft_strnstr(text, LDI_NAME, 3))
		return (TOKEN_LDI);
	else if (ft_strnstr(text, LLD_NAME, 3))
		return (TOKEN_LLD);
	else if (ft_strnstr(text, STI_NAME, 3))
		return (TOKEN_STI);
	else if (ft_strnstr(text, SUB_NAME, 3))
		return (TOKEN_SUB);
	else if (ft_strnstr(text, XOR_NAME, 3))
		return (TOKEN_XOR);
	return (0);
}

static int      find_op4_type(char const *text)
{
	if (ft_strnstr(text, FORK_NAME, 4))
		return (TOKEN_FORK);
	else if (ft_strnstr(text, LIVE_NAME, 4))
		return (TOKEN_LIVE);
	else if (ft_strnstr(text, LLDI_NAME, 4))
		return (TOKEN_LLDI);
	else if (ft_strnstr(text, ZJMP_NAME, 4))
		return(TOKEN_ZJMP);
	return (0);
}

static int      find_op5_type(char const *text)
{
	if (ft_strnstr(text, LFORK_NAME, 5))
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
    printf("text|%s\n", *text);
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
	    return (LINE_FEED_CODE);
    }
    else if (ft_strnstr(*text, ".name", 5)) {
	    (*text) += 5;
	    return (NAME_CMD_STRING_CODE);
    }
    else if (ft_strnstr(*text, ".comment", 8)){
	    (*text) += 8;
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
    	*(token_ptr) = (void*)(*text - 1);
    	return (LABEL_CHARS_CODE);
    }
    *type = TOKEN_UNDEF;
    ++(*text);
    return (TERM_UNDEFINED_CODE);
}
