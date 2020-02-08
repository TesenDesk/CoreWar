

typedef struct 	    s_token t_token;


/*
 * construction/destruction
*/


t_token*            token_constructor(int type,void *begin, size_t len);
void                token_destructor(t_token **token);

