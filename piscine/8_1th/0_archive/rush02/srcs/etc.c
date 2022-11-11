/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeseule <jaeseule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 11:59:58 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/11 22:01:27 by jaeseule         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

void	set_default(char *buf)
{
	int	idx;

	idx = 0;
	while (idx < 5)
	{
		buf[idx] = 0;
		idx++;
	}
}

char	*ft_strcat(char *dest, char *src)
{
	int	size_d;
	int	idx;

	size_d = 0;
	while (dest[size_d])
		size_d++;
	idx = 0;
	while (src[idx])
	{
		dest[size_d + idx] = src[idx];
		idx++;
	}
	dest[size_d + idx] = 0;
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	idx;

	idx = 0;
	while (src[idx])
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = 0;
	return (dest);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}
