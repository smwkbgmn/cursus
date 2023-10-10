
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

void	dbg_print_procs(t_list *l_exe)
{
	if (l_exe)
	{
		printf("------------ EXE -------------\n");
		print_procs(l_exe);
		printf("------------------------------\n");
		dbg_print_procs(l_exe->next);
	}
}

static void	print_procs(t_list *l_exe)
{
	t_execute	*exe;
	char		**av;

	if (l_exe)
	{
		exe = l_exe->content;
		if (exe->op_seq != PRNTSIS_CLS
			&& exe->op_seq != PRNTSIS_OPN)
		{
			printf("%-10s%20s\n", "name: ", exe->cmd.path);
			av = exe->cmd.av;
			printf("%-10s%20s\n", "argv: ", *av);
			av++;
			while (*av)
			{
				printf("%30s\n", *av);
				av++;
			}
			printf("%-10s%20d\n", "fd_rd[R]: ", exe->cmd.fd_rd[R]);
			printf("%-10s%20d\n", "fd_rd[W]: ", exe->cmd.fd_rd[W]);
			printf("%-10s%20s\n", "heredoc: ", exe->cmd.fname_heredoc);
		}
		printf("%-10s%20d\n", "op_seq: ", ((t_execute *)l_exe->content)->op_seq);
	}
}
