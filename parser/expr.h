#ifndef EXPR_H
#define EXPR_H



typedef struct 	    s_expr t_expr;


/*
 * construction/destruction
*/

/*
 * TOKEN TYPES
 */
//#define NO_TOKEN -1
//#define TOKEN_UNDEF 0
//#define TOKEN_INIT_ST 1
//#define TOKEN_EOF 2
//#define TOKEN_LFEED 3
//#define TOKEN_CHNAME 4
//#define TOKEN_CHCOM 5
//#define TOKEN_OPX 6
//#define TOKEN_TREG 7
//#define TOKEN_TIND_INT 8
//#define TOKEN_TIND_LAB 9
//#define TOKEN_TDIR_INT 10
//#define TOKEN_TDIR_LAB 11

t_expr*            expr_constructor(int expr_type, int size, void *begin);
void               expr_destructor(t_expr **expr);

#endif
