#include "parser.h"
#include "parser_private.h"
#include "../lexer/token_defines.h"

void     parser_change_state(t_parser *parser, int token_type)
{
    if (parser->state == INIT_ST)
    {
        if (token_type == TOKEN_CHNAME || token_type == TOKEN_CHCOM)
            parser->state = PRECODE_ST;
        else if (token_type == LA)
    }

}
