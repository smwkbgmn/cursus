/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:55:30 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/24 05:34:32 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>

int		ft_printf(const char *str, ...);

void	set_flag(char *(*flags[7])(const char *, char *));
void	set_spcf(char *(*specifiers[8])(va_list *));
short	get_flag(char c);
short	get_spcf(char c);

char	*spcf_c(va_list *ptr);
char	*spcf_d(va_list *ptr);
char	*spcf_i(va_list *ptr);
char	*spcf_p(va_list *ptr);
char	*spcf_s(va_list *ptr);
char	*spcf_u(va_list *ptr);
char	*spcf_x_lower(va_list *ptr);
char	*spcf_x_upper(va_list *ptr);

char	*flag_precision(const char *str, char *value);
// char	*flag_zero(const char *str, char *value);
// char	*flag_plus(const char *str, char *value);
// char	*flag_space(const char *str, char *value);
// char	*flag_hash(const char *str, char *value);
// char	*flag_dash(const char *str, char *value);
// char	*flag_width(const char *str, char *value);

#endif