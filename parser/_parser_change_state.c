// #include "parser.h"
#include "parser_private.h"
// #include "../lexer/token_defines.h"

//void     _parser_change_state(t_parser *parser, int token_type)
//{
//    if (parser->state == PARSER_INIT_ST)
//    {
//        if (token_type == TOKEN_CHNAME || token_type == TOKEN_CHCOM)
//            parser->state = PRECODE_ST;
//        else if (token_type == TOKEN_LABEL_WORD)
//    }
//}
//


static int  _find_parser_op0_state(int token_type)
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
	return (0); //TODO: Не было return - исправьте)
}

static int  _parser_find_next_to_init_st(int token_type)
{
	if (token_type == TOKEN_CHNAME || token_type == TOKEN_CHCOM)
		return (PARSER_LINE_END_ST);
	else if (token_type >= TOKEN_AFF && token_type <= TOKEN_LFORK)
		return (_find_parser_op0_state(token_type));
	else if (token_type == TOKEN_LABEL_WORD ||
	token_type == TOKEN_LFEED || token_type == TOKEN_EOF)
		return (PARSER_INIT_ST);
	else
		return (PARSER_ERROR);
}

static int         _find_1_0_layer_op(t_parser *parser, int token_type)
{
	if ((parser->state == PARSER_OP0_LIFE_ST && (token_type == TOKEN_TDIR_INT
												 || token_type == TOKEN_TDIR_LAB)) || (parser->state == PARSER_OP0_AFFECT_ST &&
																					   token_type == TOKEN_TREG))
		return (PARSER_LINE_END_ST);
	return (PARSER_ERROR);
}

static int 			_find_1_1_layer_op(t_parser *parser , int token_type)
{
	if (token_type == TOKEN_TREG)
	{
		if (parser->state == PARSER_OP0_ARITHM_ST)
			return (PARSER_OP1_ARITHM_ST);
		else if(parser->state == PARSER_OP0_STORE_ST)
			return (PARSER_OP1_STORE_ST);
		else if(parser->state == PARSER_OP0_STORI_ST)
			return (PARSER_OP1_STORI_ST);
		else if(parser->state == PARSER_OP0_LOADI_ST)
			return (PARSER_OP1_LOADI_ST);
		else if(parser->state == PARSER_OP0_LOGIC_ST)
			return (PARSER_OP1_LOGIC_ST);
	}
	else if (token_type == TOKEN_TDIR_LAB || token_type == TOKEN_TDIR_INT
			 || token_type == TOKEN_TIND_LAB || token_type == TOKEN_TIND_INT)
	{
		if (parser->state == PARSER_OP0_LOAD_ST)
			return (PARSER_OP1_LOAD_ST);
		else if(parser->state == PARSER_OP0_LOADI_ST)
			return (PARSER_OP1_LOADI_ST);
		else if(parser->state == PARSER_OP0_LOGIC_ST)
			return (PARSER_OP1_LOGIC_ST);
	}
	return (PARSER_ERROR);
}

static int 	_find_2_0_layer_op(t_parser *parser, int token_type)
{
	if (token_type == TOKEN_TREG)
	{
		if (parser->state == PARSER_OP1_LOAD_ST
			|| parser->state == PARSER_OP1_STORE_ST)
			return (PARSER_LINE_END_ST);
	}
	else if (token_type == TOKEN_TIND_LAB || token_type == TOKEN_TIND_INT)
	{
		if (parser->state == PARSER_OP1_STORE_ST)
			return (PARSER_LINE_END_ST);
	}
	return (PARSER_ERROR);
}


static int 	_find_2_1_layer_op(t_parser *parser, int token_type)
{
	if (token_type == TOKEN_TREG)
	{
		if (parser->state == PARSER_OP1_ARITHM_ST)
			return (PARSER_OP2_ARITHM_ST);
		else if (parser->state == PARSER_OP1_LOADI_ST)
			return (PARSER_OP2_LOADI_ST);
		else if (parser->state == PARSER_OP1_LOGIC_ST)
			return (PARSER_OP2_LOGIC_ST);
		else if (parser->state == PARSER_OP1_STORI_ST)
			return (PARSER_OP2_STORI_ST);
	}
	else if (token_type == TOKEN_TDIR_LAB || token_type == TOKEN_TDIR_INT)
	{
		if (parser->state == PARSER_OP1_LOADI_ST)
			return (PARSER_OP2_LOADI_ST);
		else if (parser->state == PARSER_OP1_LOGIC_ST)
			return  (PARSER_OP2_LOGIC_ST);
		else if (parser->state == PARSER_OP1_STORI_ST)
			return (PARSER_OP2_STORI_ST);
	}
	else if (token_type == TOKEN_TIND_LAB || token_type == TOKEN_TIND_INT)
	{
		if (parser->state == PARSER_OP1_LOGIC_ST)
			return  (PARSER_OP2_LOGIC_ST);
		else if (parser->state == PARSER_OP1_STORI_ST)
			return (PARSER_OP2_STORI_ST);
	}
	return (PARSER_ERROR);
}


static int  _parser_find_next_to_op01_st(t_parser  *parser, int token_type)
{
	if (parser->state == PARSER_OP0_LIFE_ST || parser->state == PARSER_OP0_AFFECT_ST)
		parser->state = _find_1_0_layer_op(parser, token_type);
	else if (parser->state == PARSER_OP0_LOAD_ST
			 || parser->state == PARSER_OP0_ARITHM_ST || parser->state == PARSER_OP0_LOADI_ST
			 || parser->state == PARSER_OP0_LOGIC_ST || parser->state == PARSER_OP0_STORI_ST
			 || parser->state == PARSER_OP0_STORE_ST)
		parser->state = _find_1_1_layer_op(parser, token_type);
	else if (parser->state == PARSER_OP1_LOAD_ST || parser->state == PARSER_OP1_STORE_ST)
		parser->state = _find_2_0_layer_op(parser, token_type);
	else if (parser->state == PARSER_OP1_ARITHM_ST || parser->state == PARSER_OP1_LOADI_ST
			 || parser->state == PARSER_OP1_LOGIC_ST || parser->state == PARSER_OP1_STORI_ST)
		parser->state = _find_2_1_layer_op(parser, token_type);
	else if (parser->state == PARSER_LINE_END_ST)
		parser->state = PARSER_FINISH_ST;
	else
		parser->state = PARSER_ERROR;
//	return (0); //TODO: Не было return - исправьте)
}


static int  _parser_find_next_to_op2_st(t_parser  *parser, int token_type)
{
	if (token_type == TOKEN_TREG)
		return (PARSER_LINE_END_ST);
	else if (token_type == TOKEN_TDIR_INT || token_type == TOKEN_TDIR_LAB)
		if (parser->state == PARSER_OP2_STORI_ST)
			return (PARSER_LINE_END_ST);
	return (PARSER_ERROR);

//	if (parser->state == PARSER_OP2_ARITHM_ST) {
//		if (token_type == TOKEN_);
//	}
//	if (parser->state == PARSER_OP2_LOADI_ST)
//		;
//	else if (parser->state == PARSER_OP2_LOGIC_ST)
//		;
//	else if (parser->state == PARSER_OP2_STORI_ST)
//		_parser_get_token;
//	if (token_type == TOKEN_LFEED) {
//		parser->state = PARSER_INIT_ST;
//	}
//	else{
//		parser->state = PARSER_ERROR;
//	}
//	return (0);
}


void        _parser_change_state(t_parser *parser, int token_type)
{
	if (parser->state == PARSER_INIT_ST)
		parser->state = _parser_find_next_to_init_st(token_type);
	else if (
			parser->state == PARSER_OP0_LIFE_ST
			|| 	parser->state == PARSER_OP0_AFFECT_ST
			||  parser->state == PARSER_OP0_LOAD_ST
			|| 	parser->state == PARSER_OP1_LOAD_ST
			||	parser->state == PARSER_OP0_STORE_ST
			||  parser->state == PARSER_OP1_STORE_ST
			|| 	parser->state == PARSER_OP0_ARITHM_ST
			||  parser->state == PARSER_OP1_ARITHM_ST
			|| 	parser->state == PARSER_OP0_LOADI_ST
			||  parser->state == PARSER_OP1_LOADI_ST
			||	parser->state == PARSER_OP0_LOGIC_ST
			||  parser->state == PARSER_OP1_LOGIC_ST
			||	parser->state == PARSER_OP0_STORI_ST
			||  parser->state == PARSER_OP1_STORI_ST
			)
		_parser_find_next_to_op01_st(parser,token_type);
//	else if (parser->state >= PARSER_OP2_ARITHM_ST
//	&& parser->state <= PARSER_OP2_STORI_ST)
	else if (
			parser->state == PARSER_OP2_ARITHM_ST
		  	||  parser->state == PARSER_OP2_LOADI_ST
		  	||	parser->state == PARSER_OP2_LOGIC_ST
		  	||  parser->state == PARSER_OP2_STORI_ST
			)
		parser->state = _parser_find_next_to_op2_st(parser, token_type);
	else if (parser->state == PARSER_LINE_END_ST)
	{
		if (token_type == TOKEN_LFEED)
			parser->state = PARSER_FINISH_ST;
		else
			parser->state = PARSER_ERROR;
	}
}
//PARSER_ERROR = -1,
//		PARSER_INIT_ST,
//		PARSER_OP0_LIFE_ST,
//		PARSER_OP0_AFFECT_ST,
//		PARSER_OP0_LOAD_ST,
//		PARSER_OP1_LOAD_ST,
//		PARSER_OP0_STORE_ST,
//		PARSER_OP1_STORE_ST,
//		PARSER_OP0_ARITHM_ST,
//		PARSER_OP1_ARITHM_ST,
//		PARSER_OP2_ARITHM_ST,
//		PARSER_OP0_LOADI_ST,
//		PARSER_OP1_LOADI_ST,
//		PARSER_OP2_LOADI_ST,
//		PARSER_OP0_LOGIC_ST,
//		PARSER_OP1_LOGIC_ST,
//		PARSER_OP2_LOGIC_ST,
//		PARSER_OP0_STORI_ST,
//		PARSER_OP1_STORI_ST,
//		PARSER_OP2_STORI_ST,
//		PARSER_LINE_END_ST,
//		PARSER_EOF,
//		PARSER_AR_SIZE,
