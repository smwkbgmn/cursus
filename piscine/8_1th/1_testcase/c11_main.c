/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c11_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:49:49 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/12 18:22:38 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include "ex00/ft_foreach.c"
#include "ex01/ft_map.c"
#include "ex02/ft_any.c"
#include "ex03/ft_count_if.c"
#include "ex04/ft_is_sort.c"
#include "ex07/ft_advanced_sort_string_tab.c"

int		ft_strcmp(char *s1, char *s2);
void	ft_putnbr(int nbr);
int		alt_to_negative(int n);
int		is_num(char  *str);
int		word(char **av);
int		is_sorted(int n1, int n2);

int	main(int ac, char **av)
{
	int	tab[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	if (ac < 1)
		return (0);

	av++;

	// ex00
	printf("\n[ex00]\n");
	ft_foreach(tab, 10, &ft_putnbr);
	printf("\n");
	

	// ex01
	printf("\n[ex01]\n");

	int	*tab_mapped;
	int idx;

	tab_mapped = ft_map(tab, 10, &alt_to_negative);
	
	idx = 0;
	while (idx < 10)
	{
		printf("[%d]", tab_mapped[idx]);
		idx++;
	}
	printf("\n");


	// ex02
	printf("\n[ex02]\n");
	
	printf("ft_any's return value is --- %d\n", ft_any(av, &is_num));


	// ex03
	printf("\n[ex03]\n");

	int	size;

	size = word(av);
	printf("ft_count_if's return value is --- %d\n"
			, ft_count_if(av, size, &is_num));


	// ex04
	printf("\n[ex04]\n");
	int	 t1[5] = {-2, -1, 0, 1, 2};
	int	 t2[5] = {2, 1, 0, -1, -2};
	int	 t3[5] = {0, 0, 0, 1, 2};
	int	 t4[7] = {1, 2, 3, 3, 4, 5, 5};
	int	 t5[1] = {1};
	int	 t6[1];
	int	 t7[5] = {0, -1, 2, 1, 4};
	int	 t8[5] = {0, -1, -1, 0, -2};
	int	 t9[5] = {0, -1, -2, -3, -2};

	printf("[%s] --- %d\n", "-2 -1 0 1 2", ft_is_sort(t1, 5, &is_sorted));
	printf("[%s] --- %d\n", "2 1 0 -1 -2", ft_is_sort(t2, 5, &is_sorted));
	printf("[%s] --- %d\n", "0 0 0 1 2", ft_is_sort(t3, 5, &is_sorted));
	printf("[%s] --- %d\n", "1 2 3 3 4 5 5", ft_is_sort(t4, 7, &is_sorted));
	printf("[%s] --- %d\n", "1", ft_is_sort(t5, 1, &is_sorted));
	printf("[%s] --- %d\n", "", ft_is_sort(t6, 0, &is_sorted));
	printf("[%s] --- %d\n", "0 -1 2 1 4", ft_is_sort(t7, 5, &is_sorted));
	printf("[%s] --- %d\n", "0 -1 -1 0 -2", ft_is_sort(t8, 5, &is_sorted));
	printf("[%s] --- %d\n", "0 -1 -2 -3 -2", ft_is_sort(t9, 5, &is_sorted));


	// ex07
	printf("\n[ex07]\n");
	ft_advanced_sort_string_tab(av, &ft_strcmp);
	while (*av)
	{
		printf("%s\n", *av);
		av++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == 0)
			return (0);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, &"-2147483648", 11);
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(nb * -1);
	}
	else if (nb < 10)
		write(1, &"0123456789"[nb % 10], 1);
	else
	{
		ft_putnbr(nb / 10);
		write(1, &"0123456789"[nb % 10], 1);
	}
}

int	alt_to_negative(int n)
{
	return (n * -1);
}

int	is_num(char  *str)
{
	while ('0' <= *str && *str <= '9')
		str++;
	if (*str == 0)
		return (1);
	return (0);
}

int	word(char **av)
{
	int word;

	word = 0;
	while (*av)
	{
		word++;
		av++;
	}
	return (word);
}

int	is_sorted(int n1, int n2)
{
	if (n1 < n2)
		return (-42);
	else if (n1 == n2)
		return (0);
	else
		return (42);
//	return (42);
}
