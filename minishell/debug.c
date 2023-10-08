
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

static void	print_procs(t_list *l_exe)
{
	t_execute	*exe;

	if (l_exe)
	{
		exe = l_exe->content;
		if (exe)
		{
			printf("%-10s%s\n", "name: ", exe->cmd.name);
			while (*exe->cmd.av)
			{
				printf("%-10s%s\n", "av: ", *exe->cmd.av);
				exe->cmd.av++;
			}
			printf("%-10s%d\n", "rd_in: ", exe->cmd.rd_in);
			printf("%-10s%d\n", "rd_out: ", exe->cmd.rd_out);
			printf("%-10s%s\n", "heredoc: ", exe->cmd.fname_heredoc);
		}
		printf("%-10s%d\n", "op_seq: ", ((t_execute *)l_exe->content)->op_seq);
		print_procs(l_exe->next);
	}
}