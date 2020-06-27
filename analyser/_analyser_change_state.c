//
// Created by ikira on 13.03.2020.
//


#include "analyser_private.h"
#include "_expr.h"
//#include "text_private.h"

static		void _change_init_state(t_analyser *analyser, int expr_type)
{

	if (expr_type == EXPR_CH_NAME_LINE)
		analyser->state = ANALYSER_PRECODE_NAME_ST;
	else if (expr_type == EXPR_CH_COMMENT_LINE)
		analyser->state = ANALYSER_PRECODE_COMMENT_ST;
	else
		analyser->state = ANALYSER_ERROR_ST;
}

static 		void _change_precode_state(t_analyser *analyser,
		int expr_type)
{
	if (analyser->state == ANALYSER_PRECODE_COMMENT_ST
		&& expr_type == EXPR_CH_NAME_LINE)
		analyser->state = ANALYSER_CODE_ST;
	else if (analyser->state == ANALYSER_PRECODE_NAME_ST
		&& expr_type == EXPR_CH_COMMENT_LINE)
		analyser->state = ANALYSER_CODE_ST;
	else
		analyser->state = ANALYSER_ERROR_ST;
}

void		_analyser_change_state(t_analyser *analyser, int expr_type)
{
	if (expr_type == EXPR_UNDEF) {
		analyser->state = ANALYSER_ERROR_ST;
		return ;
	}
	if (analyser->state == ANALYSER_INIT_ST)
		_change_init_state(analyser, expr_type);
	else if (analyser->state >= ANALYSER_PRECODE_NAME_ST
		&& analyser->state <= ANALYSER_PRECODE_COMMENT_ST)
		_change_precode_state(analyser, expr_type);
	else if (analyser->state == ANALYSER_CODE_ST &&
	expr_type >= 1 && expr_type <= 28)
		;
	else if(analyser->state == ANALYSER_CODE_ST &&
	expr_type == EXPR_EOF)
		analyser->state = ANALYSER_FINISH_ST;
}
