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

static int  find_parser_op0f_state(int token_type)
{
	if (token_type == TOKEN_ADD)
		return (PARSER_OP0_ADD_ST);
	else if (token_type == TOKEN_AFF)
		return (PARSER_OP0_AFF_ST);
	else if (token_type == TOKEN_AND)
		return (PARSER_OP0_AND_ST);
	else if (token_type == TOKEN_FORK)
		return (PARSER_OP0_FORK_ST);
	else if (token_type == TOKEN_LD)
		return (PARSER_OP0_LD_ST);
	else if (token_type == TOKEN_LDI)
		return (PARSER_OP0_LDI_ST);
	else if (token_type == TOKEN_LFORK)
		return (PARSER_OP0_LFORK_ST);
	else if (token_type == TOKEN_LIVE)
		return (PARSER_OP0_LIVE_ST);
}


static int  find_parser_op0l_state(int token_type)
{
	if (token_type == TOKEN_LLD)
		return (PARSER_OP0_LLD_ST);
	else if (token_type == TOKEN_LLDI)
		return (PARSER_OP0_LLDI_ST);
	else if (token_type == TOKEN_OR)
		return (PARSER_OP0_OR_ST);
	else if (token_type == TOKEN_ST)
		return (PARSER_OP0_ST_ST);
	else if (token_type == TOKEN_STI)
		return (PARSER_OP0_STI_ST);
	else if (token_type == TOKEN_SUB)
		return (PARSER_OP0_SUB_ST);
	else if (token_type == TOKEN_XOR)
		return (PARSER_OP0_XOR_ST);
	else if (token_type == TOKEN_ZJMP)
		return (PARSER_OP0_ZJMP_ST);
}


static int  find_parser_op0_state(int token_type)
{
	if (token_type >= TOKEN_ADD && token_type <= TOKEN_LIVE)
		return (find_parser_op0f_state(token_type));
	else if (token_type > TOKEN_LIVE && token_type <= TOKEN_ZJMP)
		return (find_parser_op0l_state(token_type));
}

static int  parser_find_next_to_init(int token_type)
{
	if (token_type == TOKEN_CHNAME || token_type == TOKEN_CHCOM)
		return (PARSER_PRECODE_LINE_ST);
	else if (token_type >= TOKEN_ADD && token_type <= TOKEN_TIND_LAB)
		return (find_parser_op0_state(token_type));
	else if (token_type == TOKEN_LABEL)
}

void        parser_change_state(t_parser *parser, int token_type)
{
fdfdfd
	if (parser->state == PARSER_INIT_ST)
		parser->state = parser_find_next_to_init_st(token_type);
	else if (parser->state >= NAME_CMD_ST && parser->state <= CH_COMM_ST)
		parser->state = parser_find_champ_state(parser, token_type);
//	else if (parser->state == OPX_ST || parser->state == MULTI_ARG_ST) {
//		if (token_type == REGISTER_CHAR_CODE)
//			parser->state = T_REG_ST;
//		else if (token_type == INTEGER_CODE)
//			parser->state = T_IND_INT_ST;
//		else if (token_type == LABEL_CHAR_CODE)
//			parser->state = T_IND_LABEL_ST;
//		else if (token_type == DIRECT_CHAR_CODE)
//			parser->state = T_DIR_INT_ST;
//		else
//			parser->state = INIT_ST;
//	}
//	else if (parser->state >= T_REG_ST && parser->state <= ARG_BRK_ST)
//		parser->state = parser_find_op_arg_state(parser, token_type);
//	else
//	{
//		printf("LINE_FEED_CODE %i\n", parser->state);
//		parser->state = INIT_ST;
//	}
}

int     parser_get_token_init(t_parser *parser)
{

	return (0);
}


int     parser_get_token_precode(t_parser *parser)
{
    ;
}
