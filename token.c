
#include "token_private.h"

void                token_constructor(t_token **token)
{
	if (!(*token = (t_token*)malloc(sizeof(t_token))))
	{
		printf("error\n");
		exit(-1);
	}
	(*token)->tkn_type = 0;
	(*token)->tkn_begin = NULL;
	(*token)->tkn_end = NULL;
	(*token)->tkn_len = 0;
}

void                token_destructor(t_token **token)
{
	free(*token);
	*token = NULL;
}

