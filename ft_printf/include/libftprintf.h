/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:55:30 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/11 18:20:22 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>

# include <stdio.h>

# define TRUE 1
# define FALSE 0
# define ERROR -1

int		ft_printf(const char *str, ...);
void	apply_len(int len_in, int *len_out);

short	init_list(t_list **head);
int		write_list(t_list *head, short type);
void	free_content(void *content);

short	get_conversion(char *format, t_list *head, va_list *ptr);

void	set_type(short (*types[8])(va_list *, t_list *));
short	get_type_char(char c);
short	get_type_str(char *format);
short	type_c_with_null(short type, void *content);

void	set_flag(short (*flags[7])(char *, t_list *));
short	get_flag(char c);
size_t	pass_flag(char *format, short flag);
size_t	find_flag(char *format, char flag);
char	*get_str_fill_char(int width, char c);

short	type_c(va_list *ptr, t_list *head);
short	type_d(va_list *ptr, t_list *head);
short	type_i(va_list *ptr, t_list *head);
short	type_p(va_list *ptr, t_list *head);
short	type_s(va_list *ptr, t_list *head);
short	type_u(va_list *ptr, t_list *head);
short	type_x_lower(va_list *ptr, t_list *head);
short	type_x_upper(va_list *ptr, t_list *head);

short	flag_precision(char *format, t_list *head);
short	flag_zero(char *format, t_list *head);
short	flag_plus(char *format, t_list *head);
short	flag_space(char *format, t_list *head);
short	flag_hash(char *format, t_list *head);
short	flag_dash(char *format, t_list *head);
short	flag_width(char *format, t_list *head);
short	type_percent(t_list *head);

#endif