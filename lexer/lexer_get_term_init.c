
#include "lexer.h"
#include "lexer_private.h"

static int      term_is_op(char const *text)
{
	if (ft_strnstr(text, LD_NAME, 2) || ft_strnstr(text, OR_NAME, 2)
	         || ft_strnstr(text, ST_NAME, 2))
		return (2);
    else if (ft_strnstr(text, ADD_NAME, 3) || ft_strnstr(text, AFF_NAME, 3)
	     || ft_strnstr(text, AND_NAME, 3) || ft_strnstr(text, LDI_NAME, 3)
	     || ft_strnstr(text, LLD_NAME, 3) || ft_strnstr(text, STI_NAME, 3)
	     || ft_strnstr(text, SUB_NAME, 3) || ft_strnstr(text, XOR_NAME, 3))
    	return (3);
    else if (ft_strnstr(text, FORK_NAME, 4) || ft_strnstr(text, LIVE_NAME, 4)
            || ft_strnstr(text, LLDI_NAME, 4) || ft_strnstr(text, ZJMP_NAME, 4))
    	return (4);
    else if (ft_strnstr(text, LFORK_NAME, 5))
    	return (5);
    return (0);
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
        *type = TOKEN_OPX;
    	*token_ptr = (void*)(*text);
    	*(token_ptr + 1) =  (void*)(*(text + op_len));
	    *text += op_len;
	    return (OPX_CODE);
    }
    else if (ft_strchr(LABEL_CHARS, **text))
    {
    	*token_ptr = (void*)(*text);
    	while (ft_strchr(LABEL_CHARS, *(*text)))
    		++(*text);
    	*(token_ptr) = (void*)(*text - 1);
    	return (LABEL_CHARS_CODE);
    }
    *type = TOKEN_UNDEF;
    ++(*text);
    return (TERM_UNDEFINED_CODE);
}
