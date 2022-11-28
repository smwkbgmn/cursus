/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:55:30 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/29 02:15:37 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	print_string(const char *str, va_list ptr);
void	idf_c(va_list ptr);
void	idf_d(va_list ptr);

void	idf_i(va_list ptr);
void	idf_p(va_list ptr);
void	idf_s(va_list ptr);
void	idf_u(va_list ptr);
void	idf_x_lower(va_list ptr);
void	idf_x_upper(va_list ptr);


#endif