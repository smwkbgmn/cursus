/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeseule <jaeseule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:34:15 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/12 23:01:37 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*get_f_name(int ac, char **av);
char	*apply_atoi_rule(char *av);
char	*apply(int ac, char **av);

int	main(int ac, char **av)
{
	char	*f_name;
	char	*input;
	char	**dict;
	int		mall_chk;

	if (ac != 2 && ac != 3)
		return (0);
	f_name = get_f_name(ac, av);
	if (f_name == 0)
		return (0);
	input = apply(ac, av);
	if (input == 0)
	{
		write(1, "error\n", 6);
		free(f_name);
		return (0);
	}
	mall_chk = 1;
	dict = get_dict(f_name, &mall_chk);
	if (mall_chk == 0)
		return (0);
	print(input, dict);
	free_all(f_name, input, dict);
	return (0);
}

char	*get_f_name(int ac, char **av)
{
	char	*f_name;

	if (ac == 2)
	{
		f_name = (char *)malloc(sizeof(char) * 13);
		if (f_name == 0)
		{
			free(f_name);
			return (0);
		}
		ft_strcpy(f_name, "numbers.dict\0");
	}
	else
	{
		f_name = (char *)malloc(sizeof(char) * (ft_strlen(av[1]) + 1));
		if (f_name == 0)
		{
			free(f_name);
			return (0);
		}
		ft_strcpy(f_name, av[1]);
	}
	return (f_name);
}	

char	*apply_atoi_rule(char *av)
{
	char	*input;
	int		idx;

	input = (char *)malloc(sizeof(char) * (ft_strlen(av) + 1));
	if (input == 0)
	{
		free(input);
		return (0);
	}
	av = apply_atoi_rule_tmp(av);
	if (!('0' <= *av && *av <= '9'))
	{
		*input = '0';
		return (input);
	}
	idx = 0;
	while ('0' <= *av && *av <= '9')
		input[idx++] = *av++;
	if (*av == '.')
	{
		free(input);
		return (0);
	}
	return (input);
}

char	*apply(int ac, char **av)
{
	char	*input;

	if (ac == 2)
		input = apply_atoi_rule(av[1]);
	else
		input = apply_atoi_rule(av[2]);
	return (input);
}
