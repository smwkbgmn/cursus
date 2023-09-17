
#include "minishell.h"

void	print_tokens(t_list *l_token);

void	dbg_print_token(t_list *l_token)
{
	printf("## TOKENS\n");
	print_tokens(l_token);
	printf("\n");
}

void	print_token(t_list *l_token)
{
	if (l_token)
	{
		printf("token [%s]\n", ((t_token *)l_token->content)->str);
		print_token(l_token->next);
	}
}
