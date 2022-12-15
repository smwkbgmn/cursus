/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:43:44 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/15 17:47:44 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

#include <stdio.h>
#include <stdlib.h>

static void	pass_space(const char **str);
static int	get_sign(const char **str);
static int	get_int(const char **str, int sign);
static int	ft_isdigit(char c);

int	ft_atoi(const char *str)
{
	if (*str == 0)
		return (0);
	else
	{
		pass_space(&str);
		return (get_int(&str, get_sign(&str)));
	}
}

static void	pass_space(const char **str)
{
	while ((9 <= **str && **str <= 13) || **str == ' ')
		(*str)++;
}

static int	get_sign(const char **str)
{
	if (**str == '+' || **str == '-')
	{
		if (*(*str)++ == '-')
			return (-1);
		else
			return (1);
	}
	else
		return (1);
}

static int	get_int(const char **str, int sign)
{
	long	num;

	if (ft_isdigit(**str))
	{
		num = (*(*str)++ - '0') * sign;
		if (sign > 0)
		{
			while (ft_isdigit(**str))
				num = (num * 10) + (*(*str)++ - '0');
			if (num < 0)
				return (-1);
		}
		else
		{
			while (ft_isdigit(**str))
				num = (num * 10) - (*(*str)++ - '0');
			if (num > 0)
				return (0);
		}
		return (num);
	}
	else
		return (0);
}

static int	ft_isdigit(char c)
{
	return ('0' <= c && c <= '9');
}

int main ()
{
	char	*INT_MAX = "2147483647";
	char	*INT_MAX_N = "-2147483648";
	char	*INT_MAX_OVER = "2147483648";
	char	*INT_MAX_N_OVER = "-2147483649";
	char	*LONG = "9223372036854775800";
	char	*LONG_N = "-9223372036854775800";
	char	*LONG_MAX = "9223372036854775807";
	char	*LONG_MAX_N = "-9223372036854775808";
	char	*LONG_MAX_OVER = "9223372036854775808";
	char	*LONG_MAX_N_OVER = "-9223372036854775809";
	char	*insane = "2093582037859023758902735029358209385";
	char	*insane_n = "-2093582037859023758902735029358209385";



	printf("[%d][%d]\n", atoi(INT_MAX), ft_atoi(INT_MAX));
	printf("[%d][%d]\n", atoi(INT_MAX_N), ft_atoi(INT_MAX_N));
	printf("[%d][%d]\n", atoi(INT_MAX_OVER), ft_atoi(INT_MAX_OVER));
	printf("[%d][%d]\n", atoi(INT_MAX_N_OVER), ft_atoi(INT_MAX_N_OVER));

	printf("[%d][%d]\n", atoi(LONG), ft_atoi(LONG));
	printf("[%d][%d]\n", atoi(LONG_N), ft_atoi(LONG_N));
	printf("[%d][%d]\n", atoi(LONG_MAX), ft_atoi(LONG_MAX));
	printf("[%d][%d]\n", atoi(LONG_MAX_N), ft_atoi(LONG_MAX_N));
	printf("[%d][%d]\n", atoi(LONG_MAX_OVER), ft_atoi(LONG_MAX_OVER));
	printf("[%d][%d]\n", atoi(LONG_MAX_N_OVER), ft_atoi(LONG_MAX_N_OVER));

	printf("[%d][%d]\n", atoi(insane), ft_atoi(insane));
	printf("[%d][%d]\n", atoi(insane_n), ft_atoi(insane_n));
}
