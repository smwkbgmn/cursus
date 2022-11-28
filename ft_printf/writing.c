/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 01:33:34 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/29 02:15:33 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"
#include "libft.h"

static void	set_idf(void (*idf_functions[9])(va_list ptr));
static int	get_idf(char idf);

void	print_string(const char *str, va_list ptr)
{
	void	(*idf_functions[9])(va_list);

	set_idf(idf_functions);

	while (*str)
	{
		// if (*str == '\\')
		// 	write (1, str++, 2);
		if (*str == '%' && get_idf(*(str + 1)) != -1)
		{	
			str++;
			idf_functions[get_idf(*str)](ptr);
		}
		else
			write(1, str, 1);
		str++;
	}
}

static void	set_idf(void (*idf_functions[9])(va_list ptr))
{
	idf_functions[0] = &idf_c;
	idf_functions[1] = &idf_d;
	idf_functions[2] = &idf_i;
	idf_functions[3] = &idf_p;
	idf_functions[4] = &idf_s;
	idf_functions[5] = &idf_u;
	idf_functions[6] = &idf_x_lower;
	idf_functions[7] = &idf_x_upper;
}

static int	get_idf(char idf)
{
	char	idfs[10];
	int		idx;

	ft_strlcpy(idfs, "cdipsuxX", 9);

	idx = 0;
	while (idfs[idx] != idf && idfs[idx])
		idx++;
	if (idfs[idx] == 0)
		return (-1);
	else
		return (idx);
}
