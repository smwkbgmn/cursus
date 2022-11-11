/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:28:58 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/15 11:29:35 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_map
{
	int		**map;
	int		valid;
	int		row;
	int		col;
	char	empty;
	char	obstc;
	char	full;
}	t_map;

typedef struct s_answ
{
	int	largest;
	int	row;
	int	col;
}	t_answ;

void	from_std(void);
void	from_file(int ac, char **av);

void	get_map(t_map *map, int fd);
t_answ	*get_answ(t_map *map);

int		valid_info1(t_map *map);
int		valid_map(t_map *map);

int		**default_map(int r, int c);
void	default_answ(t_answ *answ);

void	print_map(t_map *map, t_answ *answ);
void	print_map_error(void);
void	print_malloc_error(void);

void	free_map(t_map *map);

int		ft_atoi(char *str);
void	ft_putchar(char letter);
void	ft_putstr(char *str);

#endif
