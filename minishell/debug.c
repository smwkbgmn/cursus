
#include "minishell.h"

static void	print_token(t_list *l_token);
static void	print_procs(t_list *l_procs);

void	dbg_print_token(t_list *l_token)
{
	printf("------ TOKENS ------\n");
	print_token(l_token);
	printf("--------------------\n");
}

static void	print_token(t_list *l_token)
{
	if (l_token)
	{
		printf("%-15s%5d\n",
			((t_token *)l_token->content)->str,
			((t_token *)l_token->content)->type);
		print_token(l_token->next);
	}
}

void	dbg_print_procs(t_list *l_procs)
{
	printf("------ PROCS -------\n");
	print_procs(l_procs);
	printf("--------------------\n");
}

static void	print_procs(t_list *l_procs)
{
	t_process	*procs;

	if (l_procs)
	{
		procs = l_procs->content;
		printf("%-10s%s\n", "name: ", procs->exe.name);
		while (*procs->exe.av)
		{
			printf("%-10s%s\n", "av: ", *procs->exe.av);
			procs->exe.av++;
		}
		printf("%-10s%d\n", "rd_in: ", procs->exe.rd_in);
		printf("%-10s%d\n", "rd_out: ", procs->exe.rd_out);
		printf("%-10s%s\n", "heredoc: ", procs->exe.tmp_heredoc);
		print_procs(l_procs->next);
	}
}