
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
	if (!(token = (t_token*)malloc(sizeof(t_token))))
	{
		printf("error\n");
		exit(-1);
	}
	if (ptr[1] - ptr[0] < 0) {
		printf("!%.5s!\n", ptr[0]);
		printf("type:%d\n", type);
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		token->val = "";
	}
	else {
		size = ptr[1] - ptr[0] + 2;
//	printf("!!!%d, %p %p\n", type, ptr[0], ptr[1]);
		if (!(token->val = ft_memalloc(size)))
			exit(-1);
		ft_memcpy(token->val, ptr[0], size - 1);
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
	return (NULL);
}

void				*get_begin(t_token *token)
{
	return (token->token_ptr[0]);
}