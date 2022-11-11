/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 00:16:50 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/04 00:33:16 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	sorting(int argc, char *argv[]);
int		ft_strstr(char *str1, char *str2);
void	swap_pointer(char **p1, char **p2);
void	print(char *argv[]);

int	main(int argc, char *argv[])
{
	sorting(argc, argv);
	print(argv);
}

void	sorting(int argc, char *argv[])
{
	int	idx1;
	int	idx2;

	idx1 = 1;
	while (idx1 < argc - 1)
	{
		idx2 = idx1 + 1;
		while (idx2 < argc)
		{
			if (ft_strstr(argv[idx1], argv[idx2]) > 0)
				swap_pointer(&argv[idx1], &argv[idx2]);
			idx2++;
		}
		idx1++;
	}
}

int	ft_strstr(char *str1, char *str2)
{
	while (*str1 == *str2)
	{
		if (*str1 == 0)
			return (0);
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

void	swap_pointer(char **p1, char **p2)
{
	char	*temp;

	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void	print(char *argv[])
{
	argv++;
	while (*argv)
	{
		while (**argv)
		{
			write(1, *argv, 1);
			*argv += 1;
		}
		write(1, "\n", 1);
		argv += 1;
	}	
}
