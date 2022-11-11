/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c07_main_ex04.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:37:25 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/08 17:06:01 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int main(void)
{
	char *num_str;

	num_str = ft_convert_base("-2147483648", "0123456789", "0123456789");
	printf("-2147483648\n%s\n\n", num_str); 

	num_str = ft_convert_base("7FFFFFFF", "0123456789ABCDEF", "abcdefgh");
	printf("bhhhhhhhhhh\n%s\n\n", num_str); 

	num_str = ft_convert_base("bvcxzgfds", "asdfgzxcvb", "0123456789");
	printf("987654321\n%s\n\n", num_str); 

	num_str = ft_convert_base("301224003", "01234", "0123456789ABCDEF");
	printf("123DEF\n%s\n\n", num_str); 
	
	num_str = ft_convert_base("a", "abcde", "ABCDEFGHIJ");
	printf("A\n%s\n\n", num_str); 

	/////////////////////////////////////////////////////////////////////////
	
	num_str = ft_convert_base("    ---+-+-12345", "0123456789", "0123456789");
	printf("-12345\n%s\n\n", num_str); 
	
	num_str = ft_convert_base("   --+12345abc123", "0123456789", "0123456789");
	printf("12345\n%s\n\n", num_str); 
	
	num_str = ft_convert_base("a34\n5", "0123456789", "ABCDE");
	printf("A\n%s (atoi_valid 1)\n\n", num_str); 

	num_str = ft_convert_base("\b34 5", "0123456789", "abcde");
	printf("a\n%s (atoi_valid 2)\n\n", num_str); 
	
	num_str = ft_convert_base("345", "01234506789", "0123456789");
	printf("(null)\n%s (base_from_valid)\n\n", num_str); 

	num_str = ft_convert_base("345", "0", "01");
	printf("(null)\n%s (base_from_valid)\n\n", num_str); 
	
	num_str = ft_convert_base("345", "0123456789", "01234506789");
	printf("(null)\n%s (base_to_valid)\n\n", num_str); 

	return (0);
}
