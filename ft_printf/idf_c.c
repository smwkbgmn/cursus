/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idf_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:53:56 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/29 02:01:02 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	idf_c(va_list ptr)
{
	ft_putchar_fd((unsigned char)va_arg(ptr, int), 1);
}
