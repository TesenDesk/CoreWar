

typedef struct 	    s_token t_token;


void                token_form_token(t_token *token, char **text);

/*
 * public_methods
*/

void                token_constructor(t_token **token);
void                token_destructor(t_token **token);
void                token_form_token(t_token *token);

