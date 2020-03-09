#include "../lexer/lexer.h"
# include "../lexer/token.h"
# include "../lexer/token_private.h"
# include "../parser/parser.h"
# include "../parser/expr_private.h"
# include "../libf/libft.h"

void	free_token(t_token *token)
{
	ft_memdel(token->val);
	ft_memdel(token);
}

void	free_expr(t_expr *expr)
{
	size_t		i;

	ft_memdel(expr->name);
	i = 0;
	while (i < 5)
	{
		if (expr->args[i])
			free_token(expr->args[i]);
		i++;
	}
	ft_memdel(expr);
	return ;
}