//
// Created by Mudcrab Stygg on 04/02/2020.
//
#include "form_token.h"
#include "lexer_private.h"
//typedef textuct 	    s_lexer
//{
//    int             state;
//    void            *cur_token;
//    void            (*fptr_form_token)(textuct s_lexer *lexer, char **text);
//}				    t_lexer;



t_token*            form_token(t_lexer  *lexer, char **text);

void                lexer_constructor(t_lexer **lexer)
{
    if (!(*lexer = (t_lexer*)malloc(sizeof(t_lexer))))
    {
    	printf("error\n");
    	exit(-1);
    }
	(*lexer)->state = 0;
	(*lexer)->form_token = form_token;
}

void                lexer_destructor(t_lexer **lexer)
{
	free(*lexer);
	*lexer = NULL;
}


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



