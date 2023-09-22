
#include "minishell.h"

void	print_token(t_list *l_token);

void	dbg_print_token(t_list *l_token)
{
	printf("------ TOKENS ------\n");
	print_token(l_token);
	printf("--------------------\n");
}

void	print_token(t_list *l_token)
{
	if (l_token)
	{
		printf("%-15s%5d\n",
			((t_token *)l_token->content)->str,
			((t_token *)l_token->content)->type);
		print_token(l_token->next);
	}
}
