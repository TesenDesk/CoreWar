
#include "lexer.h"
#include "lexer_private.h"

static int      term_is_op(char const *text)
{
	if (strnstr(text, LD_NAME, 2) || strnstr(text, OR_NAME, 2)
	         || strnstr(text, ST_NAME, 2))
		return (2);
    else if (strnstr(text, ADD_NAME,3) || strnstr(text, AFF_NAME, 3)
	     || strnstr(text, AND_NAME, 3) || strnstr(text, LDI_NAME, 3)
	     || strnstr(text, LLD_NAME, 3) || strnstr(text, STI_NAME, 3)
	     || strnstr(text, SUB_NAME, 3) || strnstr(text, XOR_NAME, 3))
    	return (3);
    else if (strnstr(text, FORK_NAME, 4) || strnstr(text, LIVE_NAME, 4)
            || strnstr(text, LLDI_NAME, 4) || strnstr(text, ZJMP_NAME, 4))
    	return (4);
    else if (strnstr(text, LFORK_NAME, 5))
    	return (5);
    return (0);
}

int             lexer_get_term_init(t_lexer *lexer, char const **text, int *token_type, void *token_ptr[2])
{
	int op_len;

	op_len = 0;
    while (**text == ' ' || **text == '\t')
        ++(*text);
    if (!(**text))
    {
        *token_type = TOKEN_EOF;
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
    	*token_type = LINE_FEED;
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
    	*token_type = TOKEN_OPX;
    	*token_ptr = (void*)(*text);
    	*(token_ptr + 1) =  (void*)(*(text + op_len));
	    *text += op_len;
	    return (OPX_CODE);
    }
    else if (strchr(LABEL_CHARS, **text))
    {
    	*token_ptr = (void*)(*text);
    	while (strchr(LABEL_CHARS, *(*text + 1)))
    		++(*text);
    	*(token_ptr + 1) = (void*)(*text);
    	return (LABEL_CHARS_CODE);
    }
    //!!!
    return (1);
}
