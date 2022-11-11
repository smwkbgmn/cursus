/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:41:02 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/05 18:54:06 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	valid(char c1, char c2)
{
	if (c1 == c2)
		return (0);
	else
		return (1);
}	

char	*ft_strstr(char *str, char *to_find)
{
	int	s_cnt;
	int	f_cnt;
	int	check;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		if (*str == *to_find)
		{
			s_cnt = 1;
			f_cnt = 1;
			check = 0;
			while (check == 0 && (*(to_find + f_cnt)) != '\0')
			{
				check = valid (*(str + s_cnt), *(to_find + f_cnt));
				s_cnt++;
				f_cnt++;
			}
			if (check == 0)
				return (str);
		}	
		str++;
	}
	return (0);
}
