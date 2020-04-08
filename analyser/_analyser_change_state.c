//
// Created by ikira on 13.03.2020.
//


#include "analyser_private.h"
//#include "text_private.h"

static		void _change_init_state(t_analyser *analyser, int expr_type)
{

	if (expr_type == EXPR_CH_NAME_LINE)
		analyser->state = ANALYSER_PRECODE_NAME_ST;
	else if (expr_type == EXPR_CH_COMMENT_LINE)
		analyser->state = ANALYSER_PRECODE_COMMENT_ST;
	else
		analyser->state = COANALYSER_ERROR_ST;
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
		analyser->state = COANALYSER_ERROR_ST;
}

void		_change_state(t_analyser *analyser, int expr_type)
{
	if (analyser->state = ANALYSER_INIT_ST)
		_change_init_state(analyser, expr_type);
	else if (analyser->state >= ANALYSER_PRECODE_NAME_ST
		&& analyser->state <= ANALYSER_PRECODE_COMMENT_ST)
		_change_precode_state(analyser, expr_type);
}
