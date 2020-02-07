
#include "token_private.h"
#include "token.h"

void                token_constructor(int type,void *begin, size_t len)
{
	t_token         *token;
	if (!(token = (t_token*)malloc(sizeof(t_token))))
	{
		printf("error\n");
		exit(-1);
	}
	token->tkn_type = type;
	token->tkn_begin = begin;
	token->tkn_len = len;
}

void                token_destructor(t_token **token)
{
	free(*token);
	*token = NULL;
}

