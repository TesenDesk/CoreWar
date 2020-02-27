#include "parser.h"
#include "parser_private.h"
#include "../lexer/token_defines.h"



void                parser_constructor(t_parser **parser)
{
    if (!(*parser = (t_parser*)malloc(sizeof(t_parser))))
    {
        printf("error\n");
        exit(-1);
    }
    (*parser)->state = PARSER_INIT_ST;
    (*parser)->change_state = parser_change_state;
//    (*parser)->form_expr = parser_form_expr;
    (*parser)->get_token[PARSER_INIT_ST] = parser_get_token_init;
//    (*parser)->get_token[PARSER_PRECODE_LINE_ST] = parser_get_token_comment;
//    (*parser)->get_token[PARSER_CODE_COMMENT_ST] = parser_get_token_line_feed;
    /*
     *
     *
     */
//    (*parser)->get_token[LIFE_ST] = parser_get_token_line_feed;

}

void                parser_destructor(t_parser **parser)
{
    free(*parser);
    *parser = NULL;
}


static int  find_parser_op0_state(int token_type)
{
	if (token_type >= TOKEN_LIVE && token_type <= TOKEN_LFORK)
		return (PARSER_OP0_LIFE_ST);
	else if (token_type == TOKEN_AFF)
		return (PARSER_OP0_AFFECT_ST);
	else if (token_type >= TOKEN_LD && token_type <= TOKEN_LLD)
		return (PARSER_OP0_LOAD_ST);
	else if (token_type == TOKEN_ST)
		return (PARSER_OP0_STORE_ST);
	else if (token_type >= TOKEN_ADD && token_type <= TOKEN_SUB)
		return (PARSER_OP0_ARITHM_ST);
	else if (token_type >= TOKEN_LDI && token_type <= TOKEN_LLDI)
		return (PARSER_OP0_LOADI_ST);
	else if (token_type >= TOKEN_AND && token_type <= TOKEN_XOR)
		return (PARSER_OP0_LOGIC_ST);
	else if (token_type == TOKEN_STI)
		return (PARSER_OP0_STORI_ST);
}

static int  parser_find_next_to_init_st(int token_type)
{
	if (token_type == TOKEN_CHNAME || token_type == TOKEN_CHCOM)
		return (PARSER_PRECODE_LINE_ST);
	else if (token_type == TOKEN_LABEL_WORD)
		return (PARSER_LINE_END_ST);
	else if (token_type >= TOKEN_LIVE && token_type <= TOKEN_STI)
		return (find_parser_op0_state(token_type));
}

int         find_1_0_layer_op(t_ , int token_type)
{
    return ()
}

static int  parser_find_next_to_op0_st(t_parser  *parser, int token_type)
{
//		parser->state = find_op0f_st(token_type);
//	else if (parser->state > PARSER_OP0_LIVE_ST &&
//	    parser->state <= PARSER_OP0_ZJMP_ST)
//		parser->state = find_op0l_st(token_type);
        if (parser->state == PARSER_OP0_LIFE_ST || parser->state == PARSER_OP0_AFFECT_ST)
            parser->state = find_1_0_layer_op(token_type);
        else
            parser->state = find_1_1_layer_op(token_type);
}

void        parser_change_state(t_parser *parser, int token_type)
{
	if (parser->state == PARSER_INIT_ST)
		parser->state = parser_find_next_to_init_st(token_type);
	else if (parser->state >= PARSER_OP0_LIFE_ST
	&& parser->state <= PARSER_OP0_STORI_ST)
		parser->state = parser_find_next_to_op0_st(parser,token_type);
}



int     parser_get_token_precode(t_parser *parser)
{
    ;
}
