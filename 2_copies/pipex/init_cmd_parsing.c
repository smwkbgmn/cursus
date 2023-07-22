/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:13:27 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/20 23:35:54 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pass_preceed_spaces(char **input);
t_bool	is_separator(char c, t_bool dquote);
char	**init_av(int ac);
char	*copy_input(char *input, t_uint len);

char	**get_argv(char *input, int ac)
{
	static t_bool	dquote;
	char			**av;
	t_uint			idx;
	t_uint			len;

	pass_preceed_spaces(&input);
	idx = 0;
	len = 0;
	while (!is_separator(input[idx], dquote))
	{
		if (input[idx] == '"')
			dquote ^= TRUE;
		else
			len++;
		idx++;
	}
	if (input[idx] != '\0')
		av = get_argv(input + idx, ac + 1);
	else
		av = init_av(ac);
	av[ac - 1] = copy_input(input, len);
	return (av);
}

void	pass_preceed_spaces(char **input)
{
	while (**input && **input == ' ')
		*input += 1;
}

t_bool	is_separator(char c, t_bool dquote)
{
	return ((c == '\0') || (c == ' ' && !dquote));
}

char	**init_av(int ac)
{
	char	**av;

	av = ft_calloc(ac + 1, sizeof(char *));
	if (!av)
		exit_with_error("malloc");
	return (av);
}

char	*copy_input(char *input, t_uint len)
{
	char	*line;
	t_uint	idx;

	line = ft_calloc(len + 1, sizeof(char));
	if (!line)
		exit_with_error("malloc");
	idx = 0;
	while (idx < len)
	{
		if (*input == '"')
			input++;
		line[idx++] = *(input)++;
	}
	return (line);
}
