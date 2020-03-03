
#include "token.h"
#include "token_private.h"
#include "token_defines.h"

t_token				*token_constructor(int type,void *ptr[2])
{
	t_token         *token;
	if (!(token = (t_token*)malloc(sizeof(t_token))))
	{
		printf("error\n");
		exit(-1);
	}
	token->type = type;
	token->token_ptr[0] = ptr[0];
	token->token_ptr[1] = ptr[1];
	token->get_type = token_get_type;

	return (token);
}

void				token_destructor(t_token **token)
{
	free(*token);
	(*token)->token_ptr[0] = NULL;
	(*token)->token_ptr[1] = NULL;
	*token = NULL;
}

int					token_get_type(t_token *token)
{
    if (token)
        return (token->type);
    return (NO_TOKEN);
}

void				*token_get_value(t_token *token)
{
    if (token)
        return (token->val);
    return (NO_TOKEN);
}

void				*get_begin(t_token *token)
{
	return (token->token_ptr[0]);
}