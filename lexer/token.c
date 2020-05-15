
// #include "token.h"
#include "token_private.h"
// #include "token_defines.h"

t_token				*token_constructor(int type,void *ptr[2])
{
	t_token			*token;
	int 			size;
	if (ptr[1] < ptr[0] && type == TOKEN_LABEL_WORD)
	{
		printf("smth_wrong");
		exit(-1);
	}
	/*
	 * исправить эту заглушку
	 */
	if (ptr[1] < ptr[0])
		size = 10;
	else
		size = ptr[1] - ptr[0] + 2;
//	printf("!!!%d, %p %p\n", type, ptr[0], ptr[1]);
	if (!(token = (t_token*)malloc(sizeof(t_token))))
	{
		printf("error\n");
		exit(-1);
	}
	if (!(token->val = ft_memalloc(size)))
		exit(-1);
	ft_memcpy(token->val, ptr[0], size - 1);
	printf("!%s!\n", token->val);
//	printf("%d, %s\n", size -1 , token->val);
	token->type = type;
	token->token_ptr[0] = ptr[0];
	token->token_ptr[1] = ptr[1];
	token->get_type = token_get_type;
	printf("!%s!\n", token->val);

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
	printf("wow, %s\n", token->val);
	if (token)
		return (token->val);
	return (NULL);
}

void				*get_begin(t_token *token)
{
	return (token->token_ptr[0]);
}