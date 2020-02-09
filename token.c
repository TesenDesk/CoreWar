
#include "token.h"
#include "token_private.h"
#include "token_defines.h"

t_token*               token_constructor(int type,void *ptr[2])
{
	t_token         *token;
	if (!(token = (t_token*)malloc(sizeof(t_token))))
	{
		printf("error\n");
		exit(-1);
	}
	token->token_type = type;
	token->token_ptr[0] = ptr[0];
	token->token_ptr[1] = ptr[1];
	printf("ok?\n");
	return (token);
}

void                token_destructor(t_token **token)
{
	free(*token);
    (*token)->token_ptr[0] = NULL;
    (*token)->token_ptr[1] = NULL;
	*token = NULL;
}

