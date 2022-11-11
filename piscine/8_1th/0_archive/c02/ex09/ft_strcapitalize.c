/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 00:11:40 by donghyu2          #+#    #+#             */
/*   Updated: 2022/08/29 14:34:20 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init(char *str);
int		is_alpha(char letter);
int		is_num(char letter);

char	*ft_strcapitalize(char *str)
{
	int	idx;

	idx = 0;
	init(str);
	while (str[idx])
	{
		if (is_alpha(str[idx]) == 1)
		{
			if (idx == 0)
				str[idx] -= 32;
			else if (is_alpha(str[idx - 1]) == 0)
			{
				if (is_num(str[idx - 1]) == 0)
					str[idx] -= 32;
			}
		}
		idx++;
	}	
	return (str);
}

void	init(char *str)
{
	while (*str)
	{
		if ('A' <= *str && *str <= 'Z')
			*str += 32;
		str++;
	}	
}

int	is_alpha(char letter)
{
	if ('A' <= letter && letter <= 'Z')
		return (1);
	else if ('a' <= letter && letter <= 'z')
		return (1);
	else
		return (0);
}

int	is_num(char letter)
{
	if ('0' <= letter && letter <= '9')
		return (1);
	else
		return (0);
}
