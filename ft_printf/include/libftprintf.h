/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:55:30 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/08 13:50:09 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stddef.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);

void	set_spcf(size_t (*write_convert[9])(va_list *));
short	get_spcf(char spcf);

size_t	spcf_c(va_list *ptr);
size_t	spcf_d(va_list *ptr);
size_t	spcf_i(va_list *ptr);
size_t	spcf_p(va_list *ptr);
size_t	spcf_s(va_list *ptr);
size_t	spcf_u(va_list *ptr);
size_t	spcf_x_lower(va_list *ptr);
size_t	spcf_x_upper(va_list *ptr);

#endif