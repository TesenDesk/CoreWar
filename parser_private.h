
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

typedef struct 	    s_parser
{
    int             state;
    t_token*        (*parser_form_expr)(struct s_parser *parser, char const **text);
    void            (*change_state)(struct s_parser *parser, int token_type);
    /*
     *сколько состояний?
     */
    int             (*get_token[40])(struct s_parser *parser, char const **text);
}				    t_parser;

/*
 * change_state methods
 */

void                parser_change_state(t_parser *parser, int token_type);

/*
 * INIT_ST state methods
 */
int		            parser_get_token_init(t_parser *parser);

/*
 * 1lvl comment/feed methods
 */

int                parser_get_token_precode(t_parser *parser);
int		           parser_get_token_init(t_parser *parser);
 */