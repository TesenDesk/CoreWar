#ifndef PARSER_H
#define PARSER_H

#include <string.h>
#include "expr.h"
#include "expr_defines.h"




/*
** The attribute structure with no disclosed attribute.
*/
typedef struct s_parser			t_parser;

/*
** Constructor and destructor functions.
*/

void							parser_ctor(t_parser **parser);
void							parser_dtor(t_parser **parser);

/*
** Public behavioral functions.
*/
int								get_expr_type(t_expr *expr);
t_expr							*parser_form_expr(t_parser *parser,
								char const **text, t_hash_map *map,
								t_vector *vector);



#endif
