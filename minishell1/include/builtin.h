/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:18:01 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/15 15:55:03 by donghyu2         ###   ########.fr       */
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

// cd.c
char	*get_home(char *path, int *exit);
t_bool	is_dir(char *av, int *exit);

// cd_path.c
void	cd_path(char *path, int *exit);

// export_proceed.c
char	*get_exist(char *env, char **av);
t_bool	is_already_exist(char *arg, t_list *exist);
t_bool	valid_arg(char *arg);

#endif