
#ifndef TOKEN_H
#define TOKEN_H

#include <stdlib.h>
#include <stdio.h>

#include "../libft/libft.h"
#include "token_defines.h"


enum				e_t_ptr_tips
{
	TOKEN_TEXT_START_INDX = 0,
	TOKEN_TEXT_END_INDX,
};

typedef struct		s_token t_token;


/*
 * construction/destruction
*/

t_token				*token_constructor(int token_type,void *token_ptr[2]);
void				token_destructor(t_token **token);

/*
 * public
 */
int					token_get_type(t_token *token);
void				*token_get_value(t_token *token);
int					token_name_init(t_token *t);

#endif