/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 22:07:42 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/08 00:22:21 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		fstrcmp(char *str1, char *str2);
void	print_all(int argc, char ***args);

int	main(int argc, char **args)
{
	int		idx1;
	int		idx2;
	char	*temp;

	if (argc <= 1)
		return (0);
	idx1 = 0;
	while (++idx1 < argc - 1)
	{
		idx2 = idx1;
		while (++idx2 < argc)
		{
			if (fstrcmp (args[idx1], args[idx2]) > 0)
			{
				temp = args[idx1];
				args[idx1] = args[idx2];
				args[idx2] = temp;
			}
		}
	}
	print_all (argc, &args);
	return (0);
}

int	fstrcmp(char *str1, char *str2)
{
	int	cnt;

	cnt = 0;
	while (str1[cnt] == (str2[cnt]))
	{
		if (str1[cnt] == 0)
			return (0);
		cnt++;
	}
	return (str1[cnt] - str2[cnt]);
}

void	print_all(int argc, char ***args)
{
	int	idx1;
	int	idx2;

	idx1 = 1;
	while (idx1 < argc)
	{
		idx2 = 0;
		while ((*args)[idx1][idx2])
		{
			write (1, (*args)[idx1] + idx2, 1);
			idx2++;
		}
		write (1, &"\n", 1);
		idx1++;
	}
}
