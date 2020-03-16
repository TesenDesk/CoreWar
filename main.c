#include <stdio.h>

#include "token.h"
#include "token_defines.h"
#include "token_private.h"

#include "lexer.h"
#include "lexer_private.h"
#include "lexer_private.h"

#include "lexer_utils_private.h"

#include "expr.h"
#include "expr_defines.h"
#include "expr_private.h"

#include "parser.h"
#include "parser_private.h"

int main()
{
//    t_lexer *lex;
//   _lexer_constructor(&lex);
//    lex = lexer_is
//    lex = lexer_singleton_instance(LEXER_INSTANTIATE);
//    char const *str = "add aff and fork ld ldi lfork live lld lldi or st sti sub xor zjmp";
//    t_token *token1 = lexer_form_token(lex, &str);
//    printf("type %s\n", token1->type  ? "token_add" : "nope");
//    lex->state = INIT_ST;
//	token1 = lexer_form_token(lex, &str);
//	printf("type %s\n", token1->type == TOKEN_AFF ? "token_aff" : "nope");
//	lex->state = INIT_ST;
//	token1 = lexer_form_token(lex, &str);
//	printf("type %s\n", token1->type == TOKEN_AND ? "token_and" : "nope");
//	lex->state = INIT_ST;
//	token1 = lexer_form_token(lex, &str);
//	printf("type %s\n", token1->type == TOKEN_FORK ? "token_fork" : "nope");
//	lex->state = INIT_ST;
//	token1 = lexer_form_token(lex, &str);
//	printf("type %s\n", token1->type == TOKEN_LD ? "token_ld" : "nope");
//	lex->state = INIT_ST;
//	token1 = lexer_form_token(lex, &str);
//	printf("type %s\n", token1->type == TOKEN_LDI ? "token_ldi" : "nope");
//	lex->state = INIT_ST;
//	token1 = lexer_form_token(lex, &str);
//	printf("type %s\n", token1->type == TOKEN_LFORK ? "token_lfork" : "nope");
//	lex->state = INIT_ST;
//	token1 = lexer_form_token(lex, &str);
//	printf("type %s\n", token1->type == TOKEN_LIVE ? "token_live" : "nope");
//	lex->state = INIT_ST;
//	token1 = lexer_form_token(lex, &str);
//	printf("type %s\n", token1->type == TOKEN_LLD ? "token_lld" : "nope");
//	lex->state = INIT_ST;
//	token1 = lexer_form_token(lex, &str);
//	printf("type %s\n", token1->type == TOKEN_LLDI ? "token_lldi" : "nope");
//	lex->state = INIT_ST;
//	token1 = lexer_form_token(lex, &str);
//	printf("type %s\n", token1->type == TOKEN_OR ? "token_or" : "nope");
//	lex->state = INIT_ST;
//	token1 = lexer_form_token(lex, &str);
//	printf("type %s\n", token1->type == TOKEN_ST ? "token_st" : "nope");
//	lex->state = INIT_ST;
//	token1 = lexer_form_token(lex, &str);
//	printf("type %s\n", token1->type == TOKEN_STI ? "token_sti" : "nope");
//	lex->state = INIT_ST;
//	token1 = lexer_form_token(lex, &str);
//	printf("type %s\n", token1->type == TOKEN_SUB ? "token_sub" : "nope");
//	lex->state = INIT_ST;
//	token1 = lexer_form_token(lex, &str);
//	printf("type %s\n", token1->type == TOKEN_XOR ? "token_xor" : "nope");
//	lex->state = INIT_ST;
//	token1 = lexer_form_token(lex, &str);
//	printf("type %s\n", token1->type == TOKEN_ZJMP ? "token_zjmp" : "nope");
//	lex->state = INIT_ST;

// 	t_lexer *lex;
// //   _lexer_constructor(&lex);
// //    lex = lexer_is
// 	lex = lexer_singleton_instance(LEXER_INSTANTIATE);
// 	char const *str = "ld 45454, %:marker, r5     ;blabla\n";
// 	// char const *str = ".name    \"Batman\"\n";

// 	t_token *token1 = lexer_form_token(lex, &str);
// 	printf("type %i\n", token1->type);
// 	printf("str %s\n\n", (char *)token1->token_ptr[0]);

// 	t_token *token2 = lexer_form_token(lex, &str);
// 	printf("type %i\n", token2->type);
// 	printf("token2 str %s\n\n", (char *)token2->token_ptr[0]);

// 	t_token *token3 = lexer_form_token(lex, &str);
// 	printf("type %i\n", token3->type);
// 	printf("token3 str %s\n\n", (char *)token3->token_ptr[0]);

// 	t_token *token4 = lexer_form_token(lex, &str);
// 	printf("type %i\n", token4->type);
// 	printf("token4 str %s\n\n", (char *)token4->token_ptr[0]);

// 	t_token *token5 = lexer_form_token(lex, &str);
// 	printf("type %i\n", token5->type);
// 	printf("token5 str %s\n\n", (char *)token5->token_ptr[0]);



// 	// printf("%i\ns", token2->type);
// 	// printf("%s\n", token->type ==  TOKEN_TIND_INT ? "YES": "NO");




	/*
	**	Ожидаю для текста по str 10 выражений. В карту попадёт 2, в вектор -- 3
	*/

	t_parser		*prs;
	char const		*str;
	t_hash_map		*map;
	t_vector		vtr;

	t_arg			*arg;
	
	prs = parser_singleton_instance(PARSER_INSTANTIATE);
	str = 	".name	\"Batman\"\n"
			".comment	\"Batman rules!\"\n"
			"ld %0, r2    # And it is located in UNIT City\n"
			"sti r1, %:live, %1    ; UNIT City is placed in Kyiv, Ukraine\n"
			"loop:\n"
			"sti r1, %:live, %1\n"
			"live:\n"
			"live %0\n"
			"ld %0, r2\n"
			"zjmp %:loop\n";
	map = ft_hash_map_ctor(HASH_CONST);
	ft_vector_init(&vtr);

	t_expr *expr1 = parser_form_expr(prs, &str, map, &vtr); // запись в карту
	arg = expr1->args;
	printf("expr.type %i\n", expr1->type);
	printf("expr.size %i\n", expr1->size);
	printf("expr.name %p\n", expr1->name);
	printf("expr.args: "
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]\n",
				arg[0].type, arg[0].value ? (char *)(arg[0].value) : "(NULL)",
				arg[1].type, arg[1].value ? (char *)(arg[1].value) : "(NULL)",
				arg[2].type, arg[2].value ? (char *)(arg[2].value) : "(NULL)",
				arg[3].type, arg[3].value ? (char *)(arg[3].value) : "(NULL)",
				arg[4].type, arg[4].value ? (char *)(arg[4].value) : "(NULL)");

	t_expr *expr2 = parser_form_expr(prs, &str, map, &vtr);
	arg = expr2->args;
	printf("expr.type %i\n", expr2->type);
	printf("expr.size %i\n", expr2->size);
	printf("expr.name %p\n", expr2->name);
	printf("expr.args: "
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]\n",
				arg[0].type, arg[0].value ? (char *)(arg[0].value) : "(NULL)",
				arg[1].type, arg[1].value ? (char *)(arg[1].value) : "(NULL)",
				arg[2].type, arg[2].value ? (char *)(arg[2].value) : "(NULL)",
				arg[3].type, arg[3].value ? (char *)(arg[3].value) : "(NULL)",
				arg[4].type, arg[4].value ? (char *)(arg[4].value) : "(NULL)");

	t_expr *expr3 = parser_form_expr(prs, &str, map, &vtr);
	arg = expr3->args;
	printf("expr.type %i\n", expr3->type);
	printf("expr.size %i\n", expr3->size);
	printf("expr.name %p\n", expr3->name);
	printf("expr.args: "
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]\n",
				arg[0].type, arg[0].value ? (char *)(arg[0].value) : "(NULL)",
				arg[1].type, arg[1].value ? (char *)(arg[1].value) : "(NULL)",
				arg[2].type, arg[2].value ? (char *)(arg[2].value) : "(NULL)",
				arg[3].type, arg[3].value ? (char *)(arg[3].value) : "(NULL)",
				arg[4].type, arg[4].value ? (char *)(arg[4].value) : "(NULL)");

	t_expr *expr4 = parser_form_expr(prs, &str, map, &vtr);
	arg = expr4->args;
	printf("expr.type %i\n", expr4->type);
	printf("expr.size %i\n", expr4->size);
	printf("expr.name %p\n", expr4->name);
	printf("expr.args: "
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]\n",
				arg[0].type, arg[0].value ? (char *)(arg[0].value) : "(NULL)",
				arg[1].type, arg[1].value ? (char *)(arg[1].value) : "(NULL)",
				arg[2].type, arg[2].value ? (char *)(arg[2].value) : "(NULL)",
				arg[3].type, arg[3].value ? (char *)(arg[3].value) : "(NULL)",
				arg[4].type, arg[4].value ? (char *)(arg[4].value) : "(NULL)");

	t_expr *expr5 = parser_form_expr(prs, &str, map, &vtr);
	arg = expr5->args;
	printf("expr.type %i\n", expr5->type);
	printf("expr.size %i\n", expr5->size);
	printf("expr.name %p\n", expr5->name);
	printf("expr.args: "
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]\n",
				arg[0].type, arg[0].value ? (char *)(arg[0].value) : "(NULL)",
				arg[1].type, arg[1].value ? (char *)(arg[1].value) : "(NULL)",
				arg[2].type, arg[2].value ? (char *)(arg[2].value) : "(NULL)",
				arg[3].type, arg[3].value ? (char *)(arg[3].value) : "(NULL)",
				arg[4].type, arg[4].value ? (char *)(arg[4].value) : "(NULL)");

	t_expr *expr6 = parser_form_expr(prs, &str, map, &vtr);
	arg = expr6->args;
	printf("expr.type %i\n", expr6->type);
	printf("expr.size %i\n", expr6->size);
	printf("expr.name %p\n", expr6->name);
	printf("expr.args: "
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]\n",
				arg[0].type, arg[0].value ? (char *)(arg[0].value) : "(NULL)",
				arg[1].type, arg[1].value ? (char *)(arg[1].value) : "(NULL)",
				arg[2].type, arg[2].value ? (char *)(arg[2].value) : "(NULL)",
				arg[3].type, arg[3].value ? (char *)(arg[3].value) : "(NULL)",
				arg[4].type, arg[4].value ? (char *)(arg[4].value) : "(NULL)");

	t_expr *expr7 = parser_form_expr(prs, &str, map, &vtr);
	arg = expr7->args;
	printf("expr.type %i\n", expr7->type);
	printf("expr.size %i\n", expr7->size);
	printf("expr.name %p\n", expr7->name);
	printf("expr.args: "
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]\n",
				arg[0].type, arg[0].value ? (char *)(arg[0].value) : "(NULL)",
				arg[1].type, arg[1].value ? (char *)(arg[1].value) : "(NULL)",
				arg[2].type, arg[2].value ? (char *)(arg[2].value) : "(NULL)",
				arg[3].type, arg[3].value ? (char *)(arg[3].value) : "(NULL)",
				arg[4].type, arg[4].value ? (char *)(arg[4].value) : "(NULL)");

	t_expr *expr8 = parser_form_expr(prs, &str, map, &vtr);
	arg = expr8->args;
	printf("expr.type %i\n", expr8->type);
	printf("expr.size %i\n", expr8->size);
	printf("expr.name %p\n", expr8->name);
	printf("expr.args: "
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]\n",
				arg[0].type, arg[0].value ? (char *)(arg[0].value) : "(NULL)",
				arg[1].type, arg[1].value ? (char *)(arg[1].value) : "(NULL)",
				arg[2].type, arg[2].value ? (char *)(arg[2].value) : "(NULL)",
				arg[3].type, arg[3].value ? (char *)(arg[3].value) : "(NULL)",
				arg[4].type, arg[4].value ? (char *)(arg[4].value) : "(NULL)");

	t_expr *expr9 = parser_form_expr(prs, &str, map, &vtr);
	arg = expr9->args;
	printf("expr.type %i\n", expr9->type);
	printf("expr.size %i\n", expr9->size);
	printf("expr.name %p\n", expr9->name);
	printf("expr.args: "
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]\n",
				arg[0].type, arg[0].value ? (char *)(arg[0].value) : "(NULL)",
				arg[1].type, arg[1].value ? (char *)(arg[1].value) : "(NULL)",
				arg[2].type, arg[2].value ? (char *)(arg[2].value) : "(NULL)",
				arg[3].type, arg[3].value ? (char *)(arg[3].value) : "(NULL)",
				arg[4].type, arg[4].value ? (char *)(arg[4].value) : "(NULL)");

	t_expr *expr10 = parser_form_expr(prs, &str, map, &vtr);
	arg = expr10->args;
	printf("expr.type %i\n", expr10->type);
	printf("expr.size %i\n", expr10->size);
	printf("expr.name %p\n", expr10->name);
	printf("expr.args: "
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]"
				"\n\t[a.type: %i;\ta.value: %s]\n",
				arg[0].type, arg[0].value ? (char *)(arg[0].value) : "(NULL)",
				arg[1].type, arg[1].value ? (char *)(arg[1].value) : "(NULL)",
				arg[2].type, arg[2].value ? (char *)(arg[2].value) : "(NULL)",
				arg[3].type, arg[3].value ? (char *)(arg[3].value) : "(NULL)",
				arg[4].type, arg[4].value ? (char *)(arg[4].value) : "(NULL)");
	printf("\n__________\n");
	printf("map.arr_size = %zu\t - number of map entries\n", map->arr_size);
	printf("vector.total = %i\t - number of vtr entries\n", vtr.total);

	return (SUCCESS);
}
