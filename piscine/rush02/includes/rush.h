#ifndef RUSH_H
# define RUSH_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_data
{
	char	**dict;
	char	*input;
	int		len;
	char	to_find[200];
}	t_data;

void	ft_putstr(char *str);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, unsigned int nb);

char	**get_dict(char *f_name);
char	*apply_atoi_rule(char *dest, char *src);
int		get_size(char *f_name);
int		get_line(char *str);
int		get_length(char *str);

void	print(char **dict, char *input);
void    init_buffer(char *to_find);
int		print_number(t_data data);
void	print_sep(t_data data, int idx);
void	hundred(t_data *data, int *idx);
void	ten(t_data *data, int *idx);
void	one(t_data *data, int *idx);
void	unit(t_data *data, int *idx);

void free_dict(char **dict, int idx);

#endif