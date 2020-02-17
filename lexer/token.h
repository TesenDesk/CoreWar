
#ifndef TOKEN_H
#define TOKEN_H

//#include "token_private.h"
#include <stdlib.h>


typedef struct 	    s_token t_token;


/*
 * construction/destruction
*/


t_token*            token_constructor(int token_type,void *token_ptr[2]);
void                token_destructor(t_token **token);

#endif