


#ifndef PARSER_PRIVATE_H
#define PARSER_PRIVATE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expr.h"
#include "../lexer/lexer.h"
#include "../lexer/token.h"
#include "parser.h"
#include "../lexer/token_defines.h"


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


#define PARSER_OP1_LOAD_ST				22
/*
 *OP_ST_ST(2lvl) op_store_name = st_name, {white_space};
 */
#define PARSER_OP0_STORE_ST				13


#define PARSER_OP1_STORE_ST				23
/*
 * OP_ARITHM_ST(3lvl) op_arithm_name = add_name | sub_name, {white_space};*
 */
#define PARSER_OP0_ARITHM_ST            14
#define PARSER_OP1_ARITHM_ST            24
#define PARSER_OP2_ARITHM_ST            34
/*
 * OP_LOADI_ST(3lvl) op_load_i_name = ldi_name | lldi_name, {white_space};
 */
#define PARSER_OP0_LOADI_ST             15
#define PARSER_OP1_LOADI_ST             25
#define PARSER_OP2_LOADI_ST             35
/*
 * OP_LOGIC_ST(3lvl) op_logic_name = and_name | or_name | xor_name, {white_space};
 */
#define PARSER_OP0_LOGIC_ST             16
#define PARSER_OP1_LOGIC_ST             26
#define PARSER_OP2_LOGIC_ST             36
/*
 * OP_STORI_ST(3lvl) op_store_i_name = sti_name, {white_space};
 */
#define PARSER_OP0_STORI_ST				17
#define PARSER_OP1_STORI_ST				27
#define PARSER_OP2_STORI_ST				37
/*
 * OP_WAIT_LE
 */
#define PARSER_LINE_END_ST              100

typedef struct 	    s_parser
{
	int             state;
	t_lexer         *lexer;
	t_expr*        	(*form_expr)(struct s_parser *parser, char const **text);
	void            (*_change_state)(struct s_parser *parser, int token_type);
	/*
	 *сколько состояний?
	 */

	int             (*get_token[40])(struct s_parser *parser, t_lexer *lexer,
						t_expr *expr, char const **text);
}				    t_parser;

/*
 * change_state methods
 */

void                _parser_change_state(t_parser *parser, int token_type);

/*
 * INIT_ST state methods
 */
int		            parser_get_token_init(t_parser *parser, t_lexer *lexer, t_expr *expr, char const **text);



/*
 * precode_inner_methods
 */

int					parser_get_token_precode(t_parser *parser, t_lexer *lexer,
						t_expr *expr, char const **text);
int					parser_get_token_code_comment(t_parser *parser,
						t_lexer *lexer, t_expr *expr, char const **text);

/*
 * op_inner_methods
 */

int					_parser_get_token_op_life(t_parser *parser, t_lexer *lexer,
						t_expr *expr, char const **text);
int					_parser_get_token_op0_load(t_parser *parser, t_lexer *lexer,
						t_expr *expr, char const **text);
int					_parser_get_token_op1_load(t_parser *parser, t_lexer *lexer,
						t_expr *expr, char const **text);
int					_parser_get_token_op0_arit(t_parser *parser, t_lexer *lexer,
						t_expr *expr, char const **text);
int					_parser_get_token_op1_arit(t_parser *parser, t_lexer *lexer,
						t_expr *expr, char const **text);
int					_parser_get_token_op2_arit(t_parser *parser, t_lexer *lexer,
						t_expr *expr, char const **text);
int					_parser_get_token_op0_lodi(t_parser *parser, t_lexer *lexer,
						t_expr *expr, char const **text);
int					_parser_get_token_op1_lodi(t_parser *parser, t_lexer *lexer,
						t_expr *expr, char const **text);
int					_parser_get_token_op2_lodi(t_parser *parser, t_lexer *lexer,
						t_expr *expr, char const **text);
int					_parser_get_token_op0_logc(t_parser *parser, t_lexer *lexer,
						t_expr *expr, char const **text);
int					_parser_get_token_op1_logc(t_parser *parser, t_lexer *lexer,
						t_expr *expr, char const **text);
int					_parser_get_token_op2_logc(t_parser *parser, t_lexer *lexer,
						t_expr *expr, char const **text);
int					_parser_get_token_op0_stri(t_parser *parser, t_lexer *lexer,
						t_expr *expr, char const **text);
int					_parser_get_token_op1_stri(t_parser *parser, t_lexer *lexer,
						t_expr *expr, char const **text);
int					_parser_get_token_op2_stri(t_parser *parser, t_lexer *lexer,
						t_expr *expr, char const **text);
int					_parser_get_token_op0_stor(t_parser *parser, t_lexer *lexer,
						t_expr *expr, char const **text);
int					_parser_get_token_op1_stor(t_parser *parser, t_lexer *lexer,
						t_expr *expr, char const **text);
int					_parser_get_token_op_afct(t_parser *parser, t_lexer *lexer,
						t_expr *expr, char const **text);

#endif
