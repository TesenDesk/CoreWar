#ifndef EXPR_H
# define EXPR_H

//#include "expr_private.h"

typedef struct 	    s_expr t_expr;

/*
 * TOKEN TYPES
 */
#define NO_TOKEN -1
#define TOKEN_UNDEF 0
#define TOKEN_INIT_ST 1
#define TOKEN_EOF 2
#define TOKEN_LFEED 3
#define TOKEN_CHNAME 4
#define TOKEN_CHCOM 5
#define TOKEN_OPX 6
#define TOKEN_ADD 7
#define TOKEN_AFF 8
#define TOKEN_AND 9
#define TOKEN_FORK 10
#define TOKEN_LD 11
#define TOKEN_LDI 12
#define TOKEN_LFORK 13
#define TOKEN_LIVE 14
#define TOKEN_LLD 15
#define TOKEN_LLDI 16
#define TOKEN_OR 17
#define TOKEN_ST 18
#define TOKEN_STI 19
#define TOKEN_SUB 20
#define TOKEN_XOR 21
#define TOKEN_ZJMP 22
#define TOKEN_TREG 23
#define TOKEN_TIND_INT 24
#define TOKEN_TIND_LAB 25
#define TOKEN_TDIR_INT 26
#define TOKEN_TDIR_LAB 27

/*
 * construction/destruction
*/

t_expr*            expr_constructor(int expr_type,void *expr_ptr[2]);
void               expr_destructor(t_expr **expr);

#endif
