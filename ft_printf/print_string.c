/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 01:33:34 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/25 13:39:39 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

static void	set_idf(void (*idf_functions[9])(va_list));
static int	get_idf(char idf);

void	print_string(const char *str, va_list ptr)
{
	void	(*idf_functions[9])(va_list);

	// va_start(ptr, str);
	set_idf(idf_functions);

	while (*str)
	{
		if (*str == '\\')
			write (1, str++, 2);
		else if (*str == '%' && get_idf(*(str + 1)) != -1)
		{	
			str++;
			idf_functions[get_idf(*str)](ptr);
		}
		else
			write(1, str, 1);
		str++;
	}

	// va_end(ptr);
}

static void	set_idf(void (*idf_functions[9])(va_list))
{
	idf_functions[0] = &idf_c;
	// idf_functions[1] = &idf_d;
	// idf_functions[2] = &idf_i;
	// idf_functions[3] = &idf_p;
	// idf_functions[4] = &idf_s;
	// idf_functions[5] = &idf_u;
	// idf_functions[6] = &idf_x_lower;
	// idf_functions[7] = &idf_x_upper;
	// idf_functions[8] = &idf_percent;
}

static int	get_idf(char idf)
{
	char	idfs[10];
	int		idx;

	ft_strlcpy(idfs, "cdipsuxX%\0", 10);

	idx = 0;
	while (idfs[idx] != idf && idfs[idx])
		idx++;
	if (idfs[idx] == 0)
		return (-1);
	else
		return (idx);
}

// void	print_idf(va_list ptr, char idf, void (*function)(va_list))
// {
	
// }
