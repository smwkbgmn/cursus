/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeseule <jaeseule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:58:45 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/11 23:07:42 by jaeseule         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	**get_dict(char *f_name, int *mall_chk);
void	print(char *inp, char **dict);
char	*ft_strcat(char *dest, char *src);
char	*ft_strcpy(char *dest, char *src);
void	set_default(char *buf);
void	under_thousand(char *tmp, char **dict, int *len);
void	putstr(char *dict_i_str, int len);
int		parsing(char **dict, char *to_find);
int		ft_strlen(char *str);
void	free_dict(char **dict, int r);
void	free_all(char *f_name, char *input, char **dict);
char	*split_tmp(char *str);
char	*split_tmpp(char *str);
char	*apply_atoi_rule_tmp(char *av);

#endif
