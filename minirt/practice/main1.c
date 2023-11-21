#include <stdio.h>
#include <string.h>

#include "main1.h"

int exec(char **argv, char **envp, int i);
int cd(char **argv, int i);
int err(char *str);

int main(int argc, char **argv, char **envp) 
{
    int    i = 0;
    int    status = 0;

    if (argc > 1) 
    {
        while (argv[i] && argv[++i]) 
        {
            argv += i;
            i = 0;
            while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
                i++;
            if (!strcmp(*argv, "cd"))
                status = cd(argv, i);
            else if (i)
                status = exec(argv, envp, i);
        }
    }
    return status;
}

int exec(char **argv, char **envp, int i) 
{
    int fd[2];
    int status;
    int has_pipe = argv[i] && !strcmp(argv[i], "|");

    if (has_pipe && pipe(fd) == -1)
        return err("error: fatal\n");

    int pid = fork();
    if (!pid) 
    {
		// write(2, "[child]\n", 8);
		// write(2, *argv, strlen(*argv));
		// write(2, "\n", 1);
        argv[i] = 0;
        if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
            return err("error: fatal\n");
        execve(*argv, argv, envp);
        return err("error: cannot execute "), err(*argv), err("\n");
    }

	else
	{
		// write(2, "[parent]\n", 9);
		// write(2, "before\n", 7);
		waitpid(pid, &status, 0);
		// write(2, "after\n", 6);
		if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
			return err("error: fatal\n");
		return WIFEXITED(status) && WEXITSTATUS(status);
	}
}

int cd(char **argv, int i) 
{
    if (i != 2)
        return err("error: cd: bad arguments\n");
    else if (chdir(argv[1]) == -1)
        return err("error: cd: cannot change directory to "), err(argv[1]), err("\n");
    return 0;
}

int err(char *str) 
{
    while (*str)
        write(2, str++, 1);
    return 1;
}
