// #include "token_defines.h"
#include "lexer_private.h"
// #include "lexer.h"

static int      term_is_op(char const *text)
{
    if (strnstr(text, LFORK_NAME, 5))
    	return (5);
    else if (strnstr(text, FORK_NAME, 4) || strnstr(text, LIVE_NAME, 4)
             || strnstr(text, LLDI_NAME, 4) || strnstr(text, ZJMP_NAME, 4))
	    return (4);
    else if (strnstr(text, ADD_NAME, 3) || strnstr(text, AFF_NAME, 3)
             || strnstr(text, AND_NAME, 3) || strnstr(text, LDI_NAME, 3)
             || strnstr(text, LLD_NAME, 3) || strnstr(text, STI_NAME, 3)
             || strnstr(text, SUB_NAME, 3) || strnstr(text, XOR_NAME, 3))
	    return (3);
	else if (strnstr(text, LD_NAME, 2) || strnstr(text, OR_NAME, 2)
	    || strnstr(text, ST_NAME, 2))
		return (2);
	return (0);
}

static int      find_op2_type(char const *text)
{
	if (strnstr(text, LD_NAME, 2))
		return (TOKEN_LD);
	else if (strnstr(text, OR_NAME, 2))
		return (TOKEN_OR);
	else if (strnstr(text, ST_NAME, 2))
		return (TOKEN_ST);
	return (0);
}

static int      find_op3_type(char const *text)
{
	if (strnstr(text, ADD_NAME, 3))
		return (TOKEN_ADD);
	else if (strnstr(text, AFF_NAME, 3))
		return (TOKEN_AFF);
	else if (strnstr(text, AND_NAME, 3))
		return (TOKEN_AND);
	else if (strnstr(text, LDI_NAME, 3))
		return (TOKEN_LDI);
	else if (strnstr(text, LLD_NAME, 3))
		return (TOKEN_LLD);
	else if (strnstr(text, STI_NAME, 3))
		return (TOKEN_STI);
	else if (strnstr(text, SUB_NAME, 3))
		return (TOKEN_SUB);
	else if (strnstr(text, XOR_NAME, 3))
		return (TOKEN_XOR);
	return (0);
}

static int      find_op4_type(char const *text)
{
	if (strnstr(text, FORK_NAME, 4))
		return (TOKEN_FORK);
	else if (strnstr(text, LIVE_NAME, 4))
		return (TOKEN_LIVE);
	else if (strnstr(text, LLDI_NAME, 4))
		return (TOKEN_LLDI);
	else if (strnstr(text, ZJMP_NAME, 4))
		return(TOKEN_ZJMP);
	return (0);
}

static int      find_op5_type(char const *text)
{
	if (strnstr(text, LFORK_NAME, 5))
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
	    return (LINE_FEED_CODE);
    }
    else if (strnstr(*text, ".name", 5)) {
	    (*text) += 5;
	    return (NAME_CMD_STRING_CODE);
    }
    else if (strnstr(*text, ".comment", 8)){
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
	else if (**text == TOKEN_EOF)
	{
		*type = TOKEN_EOF;
		return (EOF_CODE);
	}
    *type = (TOKEN_UNDEF);
    ++(*text);
    return (TERM_UNDEFINED_CODE);
}
