


#ifndef PARSER_PRIVATE_H
#define PARSER_PRIVATE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expr.h"
#include "../lexer/lexer.h"
#include "../token/token.h"
#include "../token/token_defines.h"

#define PARSER_INIT_ST 0
#define PARSER_PRECODE_ST 1
#define PARSER_CODE_COMMENT_ST 2
#define PARSER_LIFE_ST 2

typedef struct 	    s_parser
{
    int             state;
    t_lexer         *lexer;
    t_token*        (*parser_form_expr)(struct s_parser *parser, t_lexer *lexer, char const **text);
    void            (*change_state)(struct s_parser *parser, int token_type);
    /*
     *сколько состояний?
     */
    int             (*get_token[30])(struct s_parser *parser, t_lexer *lexer, t_expr *expr, char const **text);
}				    t_parser;

/*
 * change_state methods
 */

void                parser_change_state(t_parser *parser, int token_type);

/*
 * INIT_ST state methods
 */
int		            parser_get_token_init(t_parser *parser, t_lexer *lexer, t_expr *expr, char const **text);



/*
 * precode_inner_methods
 */

int                 parser_get_token_precode(t_parser *parser, t_lexer *lexer, t_expr *expr, char const **text);
int                 parser_get_token_code_comment(t_parser *parser, t_lexer *lexer, t_expr *expr, char const **text);

/*
 * op_inner_methods
 */

int                 parser_get_token_op_life(t_parser *parser, t_lexer *lexer, t_expr *expr, char const **text);
int                 parser_get_token_op_load0(t_parser *parser, t_lexer *lexer, t_expr *expr, char const **text);
int                 parser_get_token_op_load1(t_parser *parser, t_lexer *lexer, t_expr *expr, char const **text);
int                 parser_get_token_op_arit0(t_parser *parser, t_lexer *lexer, t_expr *expr, char const **text);
int                 parser_get_token_op_arit1(t_parser *parser, t_lexer *lexer, t_expr *expr, char const **text);
int                 parser_get_token_op_arit2(t_parser *parser, t_lexer *lexer, t_expr *expr, char const **text);
int                 parser_get_token_op_lodi0(t_parser *parser, t_lexer *lexer, t_expr *expr, char const **text);
int                 parser_get_token_op_lodi1(t_parser *parser, t_lexer *lexer, t_expr *expr, char const **text);
int                 parser_get_token_op_lodi2(t_parser *parser, t_lexer *lexer, t_expr *expr, char const **text);
int                 parser_get_token_op_logc0(t_parser *parser, t_lexer *lexer, t_expr *expr, char const **text);
int                 parser_get_token_op_logc1(t_parser *parser, t_lexer *lexer, t_expr *expr, char const **text);
int                 parser_get_token_op_logc2(t_parser *parser, t_lexer *lexer, t_expr *expr, char const **text);
int                 parser_get_token_op_stri0(t_parser *parser, t_lexer *lexer, t_expr *expr, char const **text);
int                 parser_get_token_op_stri1(t_parser *parser, t_lexer *lexer, t_expr *expr, char const **text);
int                 parser_get_token_op_stri2(t_parser *parser, t_lexer *lexer, t_expr *expr, char const **text);
int                 parser_get_token_op_stor0(t_parser *parser, t_lexer *lexer, t_expr *expr, char const **text);
int                 parser_get_token_op_stor1(t_parser *parser, t_lexer *lexer, t_expr *expr, char const **text);
int                 parser_get_token_op_afct(t_parser *parser, t_lexer *lexer, t_expr *expr, char const **text);

#endif
