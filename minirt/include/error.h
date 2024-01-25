/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 01:36:42 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/24 12:21:51 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdlib.h>
# include <stdio.h>

# define ERROR -1

// error.c
void	*try(void *ptr);
void	err_sys(char *msg);
void	err_usr(char *msg);

#endif