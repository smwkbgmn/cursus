#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "/Users/donghyun/dev/cursus/1_archive/libft/libft.h"
// #include "libft.h"

int main(int ac, char **av)
{
	char	*line;

	while (*av && ac)
	{
		// write(1, *av, 2);
		while (1)
		{
			line = get_next_line(0);
			if (!line)
				break ;
			write(1, line, ft_strlen(line) + (ft_strlen(line) == 0));
			// write(1, line, ft_strlen(line));
			// ft_printf("%s", line);
		}
		// printf("len : %lu\n", strlen(*av));
		av++;
	}
}

// int main(void)
// {
// 	static int	fd[3];

// 	printf("before piping %d, %d, %d\n", fd[0], fd[1], fd[2]);
// 	pipe(fd);
// 	printf("read %d, write %d, [2] %d\n", fd[0], fd[1], fd[2]);
// 	close(fd[1]);
// 	printf("just closed write-end\n");
// 	pipe(fd);
// 	printf("and just did re-pipe fds\n");
// 	printf("read %d, write %d, [2] %d\n", fd[0], fd[1], fd[2]);
// 	system("leaks a.out");
// }

// int	main(void)
// {
// 	// char	*av[] = {"ls", "-l", NULL};
// 	// char	*env[] = {NULL};
// 	pid_t	id;
// 	// int		fd_out;

// 	id = fork();
// 	// fd_out = open("out", O_WRONLY);
// 	if (!id)
// 	{
// 		// dup2(fd_out, 1);
// 		// execve("/bin/ls", av, env);
// 		printf("hi im child\n");
// 		exit(0);
// 	}
// 	// else
// 	// 	wait(NULL);
// 	printf("hello im here\n");
// 	return (0);
// }

// int main()
// {
// 	pid_t	id1, id2, id3;

// 	printf("THE MAIN %d\n\n", getpid());

// 	printf("id1\n");
// 	id1 = fork();
// 	if (!id1)
// 		printf("\t\tfrom %d, I'm %d\n", getppid(), getpid());
// 	else
// 	{
// 		printf("\tfrom %d, I'm %d, create %d\n", getppid(), getpid(), id1);
// 		sleep(1);
// 	}

// 	printf("id2\n");
// 	id2 = fork();
// 	if (!id2)
// 		printf("\t\tfrom %d, I'm %d\n", getppid(), getpid());
// 	else
// 	{
// 		printf("\tfrom %d, I'm %d, create %d\n", getppid(), getpid(), id2);
// 		sleep(1);
// 	}

// 	printf("id3\n");
// 	id3 = fork();
// 	if (!id3)
// 		printf("\t\tfrom %d, I'm %d\n", getppid(), getpid());
// 	else
// 	{
// 		printf("\tfrom %d, I'm %d, create %d\n", getppid(), getpid(), id3);
// 		sleep(1);
// 	}
// 	return (0);
// }

// int main()
// {
// 	pid_t	id1, id2, id3;

// 	printf("THE MAIN %d\n\n", getpid());

// 	printf("id1\n");
// 	id1 = fork();
// 	if (!id1)
// 		printf("\t\tchild %d, from %d\n", getpid(), getppid());
// 	else
// 	{
// 		printf("\tparent %d, from %d, create %d\n", getpid(), getppid(), id1);
// 		sleep(1);
// 	}

// 	printf("id2\n");
// 	id2 = fork();
// 	if (!id2)
// 		printf("\t\tchild %d, from %d\n", getpid(), getppid());
// 	else
// 	{
// 		printf("\tparent %d, from %d, create %d\n", getpid(), getppid(), id2);
// 		sleep(1);
// 	}

// 	printf("id3\n");
// 	id3 = fork();
// 	if (!id3)
// 		printf("\t\tchild %d, from %d\n", getpid(), getppid());
// 	else
// 	{
// 		printf("\tparent %d, from %d, create %d\n", getpid(), getppid(), id3);
// 		sleep(1);
// 	}
// 	return (0);
// }

// int main(void)
// {
// 	pid_t	pid;
// 	int		status;
// 	int		pid_dead;

// 	pid = fork();
// 	if (!pid)
// 	{
// 		// sleep(1);
// 		printf("\t [child process %d] created from %d\n", getpid(), getppid());
// 		exit(0);
// 	}
// 	printf("[parent process %d] create %d process, ppid:%d\n", getpid(),pid,getppid()); 
// 	return (0);
//  }