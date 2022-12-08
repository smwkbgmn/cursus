/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:55:30 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/08 22:01:31 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>

int		ft_printf(const char *str, ...);

void	set_flag(int (*flag[7])(const char *, va_list *));
short	get_flag(char c);
void	set_spcf(int (*write_convert[9])(va_list *));
short	get_spcf(char c);

int	spcf_c(va_list *ptr);
int	spcf_d(va_list *ptr);
int	spcf_i(va_list *ptr);
int	spcf_p(va_list *ptr);
int	spcf_s(va_list *ptr);
int	spcf_u(va_list *ptr);
int	spcf_x_lower(va_list *ptr);
int	spcf_x_upper(va_list *ptr);
int	spcf_percent(va_list *ptr);

#endif