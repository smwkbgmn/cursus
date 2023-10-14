/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:18:01 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/14 20:20:35 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <sys/stat.h>

typedef struct stat	t_stat;

void	bltin_cd(char **av);
void	bltin_pwd(void);
void	bltin_exit(char **av);
void	bltin_echo(char **av);
void	bltin_unset(char **av);
void	bltin_env(void);
void	bltin_export(char **av);

// export_proceed.c
char	*get_exist(char *env, char **av);
t_bool	is_already_exist(char *arg, t_list *exist);
t_bool	valid(char *arg);

#endif