#define MATCH 0
#define R 0
#define W 1

#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

#include <stdio.h>

int	get_position(char **av);
int	execute(char **av, char **env, int ptr);

int	main(int ac, char **av, char **env)
{
	static int	ptr;
	static int	exit;

	if (ac > 1)
	{
		while (av[ptr] && av[++ptr])
		{
			av += ptr;
			ptr = get_position(av);

			if (ptr)
				exit = execute(av, env, ptr);	
		}
	}
	return (exit);
}

int	get_position(char **av)
{
	int	ptr;

	ptr = 0;
	while (av[ptr]
		&& strcmp(av[ptr], "|") != MATCH
		&& strcmp(av[ptr], ";") != MATCH)
		ptr++;
	return (ptr);
}

int	execute(char **av, char **env, int ptr)
{
	pid_t	pid;
	int		fd[2];
	int		pipemode = (av[ptr] && strcmp(av[ptr], "|") != MATCH);
	int		exit;

	// write(STDERR_FILENO, "executing\n", 10);

	if (pipemode)
		pipe(fd);
	
	pid = fork();
	if (pid)
	{
		waitpid(pid, &exit, 0);
		if (pipemode)
		{
			dup2(fd[R], STDIN_FILENO);
			close(fd[R]);
			close(fd[W]);
		}
		return (WIFEXITED(exit) && WEXITSTATUS(exit));
	}
	else
	{
		av[ptr] = NULL;
		if (pipemode)
		{
			dup2(fd[W], STDOUT_FILENO);
			close(fd[R]);
			close(fd[W]);
		}
		execve(*av, av, env);
		write(STDERR_FILENO, "execve error\n", 13);
		return (EXIT_FAILURE);
	}
}
