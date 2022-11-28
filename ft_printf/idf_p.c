/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idf_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:54:11 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/29 02:02:33 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"
#include "libft.h"

void	idf_p(va_list ptr)
{
	unsigned long	addr;

	addr = (unsigned long)va_arg(ptr, void *);
	write(1, "0x", 2);
	write_hex_lower(addr);
}