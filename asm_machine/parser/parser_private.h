/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:17:20 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/26 19:59:50 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_PRIVATE_H
# define PARSER_PRIVATE_H


# include "lexer.h"
# include "parser.h"
# include "expr.h"
# include "expr_defines.h"
# include "prvt_expr.h"
# include "label_checker.h"

enum				e_parser_defines
{
	PARSER_ERROR = -1,
	PARSER_INIT_ST,
	PARSER_OP0_LIFE_ST,
	PARSER_OP0_AFFECT_ST,
	PARSER_OP0_LOAD_ST,
	PARSER_OP1_LOAD_ST,
	PARSER_OP0_STORE_ST,
	PARSER_OP1_STORE_ST,
	PARSER_OP0_ARITHM_ST,
	PARSER_OP1_ARITHM_ST,
	PARSER_OP2_ARITHM_ST,
	PARSER_OP0_LOADI_ST,
	PARSER_OP1_LOADI_ST,
	PARSER_OP2_LOADI_ST,
	PARSER_OP0_LOGIC_ST,
	PARSER_OP1_LOGIC_ST,
	PARSER_OP2_LOGIC_ST,
	PARSER_OP0_STORI_ST,
	PARSER_OP1_STORI_ST,
	PARSER_OP2_STORI_ST,
	PARSER_LINE_END_ST,
	PARSER_FINISH_ST,
	PARSER_EOF,
	PARSER_AR_SIZE,
};

typedef struct		s_parser
{
	int				state;
	t_lexer			*lexer;
	t_expr			*(*form_expr)(struct s_parser *parser, char const **text,
						t_hash_map *map, t_vector *vector);
	void			(*change_state)(struct s_parser *parser, int token_type);
	t_token			*(*get_token[PARSER_AR_SIZE])(struct s_parser *parser,
						t_lexer *lexer, t_expr *expr, char const **text);
}					t_parser;

void				prvt_parser_change_state(t_parser *parser, int token_type);

int					prvt_parser_find_next_to_init_st(int token_type);
int					prvt_parser_find_next_to_op01_st(t_parser *parser,
							int token_type);
int					prvt_parser_find_next_to_op2_st(t_parser *parser,
							int token_type);

int					prvt_find_parser_op0_state(int token_type);
int					prvt_find_1_0_layer_op(t_parser *parser, int token_type);
int					prvt_find_1_1_layer_op(t_parser *parser, int token_type);
int					prvt_find_2_0_layer_op(t_parser *parser, int token_type);
int					prvt_find_2_1_layer_op(t_parser *parser,
							int token_type);

t_token				*prvt_parser_get_token_init(t_parser *parser,
							t_lexer *lexer, t_expr *expr, char const **text);
t_token				*prvt_parser_get_token_op0_life(t_parser *parser,
							t_lexer *lexer, t_expr *expr, char const **text);
t_token				*prvt_parser_get_token_op0_load(t_parser *parser,
							t_lexer *lexer, t_expr *expr, char const **text);
t_token				*prvt_parser_get_token_op1_load(t_parser *parser,
							t_lexer *lexer, t_expr *expr, char const **text);
t_token				*prvt_parser_get_token_op0_arit(t_parser *parser,
							t_lexer *lexer, t_expr *expr, char const **text);
t_token				*prvt_parser_get_token_op1_arit(t_parser *parser,
							t_lexer *lexer, t_expr *expr, char const **text);
t_token				*prvt_parser_get_token_op2_arit(t_parser *parser,
							t_lexer *lexer, t_expr *expr, char const **text);
t_token				*prvt_parser_get_token_op0_lodi(t_parser *parser,
							t_lexer *lexer, t_expr *expr, char const **text);
t_token				*prvt_parser_get_token_op1_lodi(t_parser *parser,
							t_lexer *lexer, t_expr *expr, char const **text);
t_token				*prvt_parser_get_token_op2_lodi(t_parser *parser,
							t_lexer *lexer, t_expr *expr, char const **text);
t_token				*prvt_parser_get_token_op0_logc(t_parser *parser,
							t_lexer *lexer, t_expr *expr, char const **text);
t_token				*prvt_parser_get_token_op1_logc(t_parser *parser,
							t_lexer *lexer, t_expr *expr, char const **text);
t_token				*prvt_parser_get_token_op2_logc(t_parser *parser,
							t_lexer *lexer, t_expr *expr, char const **text);
t_token				*prvt_parser_get_token_op0_stri(t_parser *parser,
							t_lexer *lexer, t_expr *expr, char const **text);
t_token				*prvt_parser_get_token_op1_stri(t_parser *parser,
							t_lexer *lexer, t_expr *expr, char const **text);
t_token				*prvt_parser_get_token_op2_stri(t_parser *parser,
							t_lexer *lexer, t_expr *expr, char const **text);
t_token				*prvt_parser_get_token_op0_stor(t_parser *parser,
							t_lexer *lexer, t_expr *expr, char const **text);
t_token				*prvt_parser_get_token_op1_stor(t_parser *parser,
							t_lexer *lexer, t_expr *expr, char const **text);
t_token				*prvt_parser_get_token_op0_afct(t_parser *parser,
							t_lexer *lexer, t_expr *expr, char const **text);
t_token				*prvt_parser_get_token_line_end(t_parser *parser,
							t_lexer *lexer, t_expr *expr, char const **text);

#endif
