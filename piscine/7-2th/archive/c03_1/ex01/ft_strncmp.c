/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:28:34 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/07 22:17:35 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	cnt;

	if (n == 0)
			return (0);
	cnt = 0;
	while (s1[cnt] == s2[cnt] && cnt < n)
	{
		if (s1[cnt] == '\0')
			return (0);
		else if (cnt == n - 1)
			return (0);
		cnt++;
	}
	return (s1[cnt] - s2[cnt]);
}
