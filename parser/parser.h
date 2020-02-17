#ifndef PARSER_H
#define PARSER_H

#include <string.h>
#include "expr.h"
#include "expr_defines.h"




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

t_expr			                *form_expr(t_parser *parser, char const **text);



#endif
