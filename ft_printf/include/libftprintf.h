/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:55:30 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/30 01:07:27 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stddef.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	writing(const char *str, va_list *ptr);
void	spcf_c(va_list *ptr);
void	spcf_d(va_list *ptr);

void	spcf_i(va_list *ptr);
void	spcf_p(va_list *ptr);
void	spcf_s(va_list *ptr);
void	spcf_u(va_list *ptr);
void	spcf_x_lower(va_list *ptr);
void	spcf_x_upper(va_list *ptr);

#endif