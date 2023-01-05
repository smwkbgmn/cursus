/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:55:30 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/04 12:43:31 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>

int		ft_printf(const char *str, ...);

t_list	*get_list(const char *str, va_list *ptr, size_t len_f);

void	set_type(t_list *(*types[8])(va_list *));
short	get_type(char c);
short	find_type(const char *str);
t_list	*check_percent(const char *str);

void	set_flag(void (*flags[7])(const char *, t_list **head));
short	get_flag(char c);
size_t	pass_flag(const char *str);
size_t	find_flag(const char *str, char flag);
char	*get_str_fill_char(int width, char c);

t_list	*type_c(va_list *ptr);
t_list	*type_d(va_list *ptr);
t_list	*type_i(va_list *ptr);
t_list	*type_p(va_list *ptr);
t_list	*type_s(va_list *ptr);
t_list	*type_u(va_list *ptr);
t_list	*type_x_lower(va_list *ptr);
t_list	*type_x_upper(va_list *ptr);

void	flag_precision(const char *str, t_list **head);
void	flag_zero(const char *str, t_list **head);
void	flag_plus(const char *str, t_list **head);
void	flag_space(const char *str, t_list **head);
void	flag_hash(const char *str, t_list **head);
void	flag_dash(const char *str, t_list **head);
void	flag_width(const char *str, t_list **head);

#endif