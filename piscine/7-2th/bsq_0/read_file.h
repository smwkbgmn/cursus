/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pji <pji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:38:09 by pji               #+#    #+#             */
/*   Updated: 2022/06/08 22:05:41 by pji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_FILE_H
# define READ_FILE_H

# define FREE_MAP -1

char	**read_file(char *file_name, char *icon);
char	*read_file_row(int filds, int size);
int		read_first(int filds, char *icon);
char	**read_map(int filds, int len_col);
int		free_row(char *row);
#endif
