/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:18:01 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/12 17:09:08 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

// # include "libft.h"
# include "../../archive/libft/libft.h"

# define SUCCESS 0
# define ERROR -1

void	*errext(void *ptr);
void	exit_error(char *msg);

#endif