/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:55:30 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/15 02:19:54 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# include "libft.h"

# define ERROR -1

void	apply_len(int len_in, int *len_out);

t_bool	init_list(t_list **head);
int		write_list(t_list *head, short type);
void	free_content(void *content);

t_bool	get_conversion(char *format, t_list *head, va_list *ptr);

void	set_type(t_bool (*types[8])(va_list *, t_list *));
short	get_type_char(char c);
short	get_type_str(char *format);
t_bool	type_c_with_null(short type, void *content);

void	set_flag(t_bool (*flags[7])(char *, t_list *));
short	get_flag(char c);
size_t	pass_flag(char *format, short flag);
int		find_flag(char *format, char flag);
char	*get_str_fill_char(int width, char c);

t_bool	type_c(va_list *ptr, t_list *head);
t_bool	type_d(va_list *ptr, t_list *head);
t_bool	type_i(va_list *ptr, t_list *head);
t_bool	type_p(va_list *ptr, t_list *head);
t_bool	type_s(va_list *ptr, t_list *head);
t_bool	type_u(va_list *ptr, t_list *head);
t_bool	type_x_lower(va_list *ptr, t_list *head);
t_bool	type_x_upper(va_list *ptr, t_list *head);
t_bool	type_percent(t_list *head);

t_bool	flag_precision(char *format, t_list *head);
t_bool	flag_zero(char *format, t_list *head);
t_bool	flag_plus(char *format, t_list *head);
t_bool	flag_space(char *format, t_list *head);
t_bool	flag_hash(char *format, t_list *head);
t_bool	flag_dash(char *format, t_list *head);
t_bool	flag_width(char *format, t_list *head);

#endif