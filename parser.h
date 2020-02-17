#ifndef PARSER_H
#define PARSER_H

#include <string.h>
#include "parser.h"
#include "parser_private.h"




/*
** The attribute structure with no disclosed attribute.
*/
typedef struct s_parser          t_parser;

/*
** Constructor and destructor functions.
*/

void			                parser_constructor(t_parser **parser);
void			                parser_destructor(t_parser **parser);

/*
** Public behavioral functions.
*/

t_expr			                *parser_form_expr(t_parser *parser, char const **text);


#endif
