
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

typedef struct 	    s_parser
{
    int             state;
    t_token*        (*parser_form_expr)(struct s_parser *parser, char const **text);
    void            (*change_state)(struct s_parser *parser, int token_type);
    int             (*get_token[15])(struct s_parser *parser, char const **text);
}				    t_parser;

