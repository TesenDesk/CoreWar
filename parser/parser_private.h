


#ifndef PARSER_PRIVATE_H
#define PARSER_PRIVATE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expr.h"
#include "../lexer/lexer.h"
#include "../lexer/token.h"

/*
 * PARSER STATE MACHINE STATES
 */
#define PARSER_INIT_ST 0
#define PARSER_PRECODE_LINE_ST 1
#define PARSER_CODE_COMMENT_ST 2
#define PARSER_LIFE_ST 3
/*
 * OP_LIFE_ST(1lvl)  op_life_name = live_name | zjmp_name | fork_name | lfork_name, {white_space};
 */
#define PARSER_OP0_LIFE_ST              10
/*
 * OP_AFFCT_ST(1lvl) op_affect_name = aff_name, {white_space};
 */
#define PARSER_OP0_AFFECT_ST		    11
/*
 * OP_LOAD_ST(2lvl) op_load_name = ld_name | lld_name, {white_space};
 */
#define PARSER_OP0_LOAD_ST				12
/*
 *OP_ST_ST(2lvl) op_store_name = st_name, {white_space};
 */
#define PARSER_OP0_STORE_ST				13
/*
 * OP_ARITHM_ST(3lvl) op_arithm_name = add_name | sub_name, {white_space};*
 */
#define PARSER_OP0_ARITHM_ST            14
/*
 * OP_LOADI_ST(3lvl) op_load_i_name = ldi_name | lldi_name, {white_space};
 */
#define PARSER_OP0_LOADI_ST             15
/*
 * OP_LOGIC_ST(3lvl) op_logic_name = and_name | or_name | xor_name, {white_space};
 */
#define PARSER_OP0_LOGIC_ST             16
/*
 * OP_STORI_ST(3lvl) op_store_i_name = sti_name, {white_space};
 */
#define PARSER_OP0_STORI_ST				25
/*
 * OP_WAIT_LE
 */
#define PARSER_LINE_END_ST              100

typedef struct 	    s_parser
{
    int             state;
    t_lexer         *lexer;
    t_token*        (*parser_form_expr)(struct s_parser *parser, t_lexer *lexer, char const **text);
    void            (*change_state)(struct s_parser *parser, int token_type);
    /*
     *сколько состояний?
     */

    int             (*get_token[11][4])(struct s_parser *parser, t_lexer *lexer, t_expr *expr, char const **text);
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
