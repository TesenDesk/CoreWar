#include "parser.h"
#include "parser_private.h"



void                parser_constructor(t_parser **parser)
{
    if (!(*parser = (t_parser*)malloc(sizeof(t_parser))))
    {
        printf("error\n");
        exit(-1);
    }
    (*parser)->state = INIT_ST;
    (*parser)->change_state = parser_change_state;
    (*parser)->parser_form_expr = parser_form_expr;
    (*parser)->get_token[INIT_ST] = parser_get_token_init;
    (*parser)->get_token[COMMENT_ST] = parser_get_token_comment;
    (*parser)->get_token[LINE_FEED_ST] = parser_get_token_line_feed;
}

void                parser_destructor(t_parser **parser)
{
    free(*parser);
    *parser = NULL;
}


void     parser_change_state(t_parser *parser, int token_type)
{
    ;
}

int     parser_get_token_init(t_parser *parser)
{
        ;
}


int     parser_get_token_precode(t_parser *parser)
{
    ;
}
