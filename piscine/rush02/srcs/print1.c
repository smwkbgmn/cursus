#include "rush.h"

void	digit(t_data *data, int position, int *idx);
int		unit_valid(t_data data, int idx);

void	print(char **dict, char *input)
{
	t_data	data;
	int	idx;

	data.dict = dict;
	data.input = apply_atoi_rule(input, input);
	data.len = ft_strlen(data.input);
	
	idx = 0;
	while (0 <= idx && idx < data.len)
	{
		digit(&data, (data.len - idx - 1) % 3, &idx);
		if (idx < 0)
			break ;
		if (unit_valid(data, idx) == 1)
			unit(&data, &idx);
		idx++;
	}
	free_dict(data.dict, -1);
}

void digit(t_data *data, int position, int *idx)
{
	if (data->input[*idx] != '0' ||
	(data->input[*idx] == '0' && data->len == 1))
	{
		init_buffer(data->to_find);
		if (position == 2)
			hundred(data, idx);
		else if (position == 1)
			ten(data, idx);
		else
			one(data, idx);
			
		if (print_number(*data) != 1)
		{
			*idx = -42;
			return ;
		}
		print_sep(*data, *idx);
	}
}

int	unit_valid(t_data data, int idx)
{
	int cnt;

	if (data.len - idx == 1)
		return (0);	
	if ((data.len - idx - 1) % 3 != 0)
		return (0);
	
	cnt = 0;
	while (cnt++ < 3 && idx >= 0)
	{
		if (data.input[idx] != '0')
			return (1);
		cnt++;
		idx--;
	}
	return (0);
}

int	print_number(t_data data)
{
	int	idx;

	while (*(data.dict))
	{
		idx = 0;
		while ((*data.dict)[idx] == data.to_find[idx])
		{
			if (data.to_find[idx] == ':')
			{
				ft_putstr(&(*data.dict)[idx + 1]);
				return (1);
			}
			idx++;
		}
		data.dict += 1;
	}

	write(1, "Dict Error\n", 11);
	return (-42);
}

void print_sep(t_data data, int idx)
{
	if (unit_valid(data, idx) == 0)
	{
		data.input += idx + 1;
		while (*data.input == '0')
			data.input += 1;

		if (data.len - idx == 1 || *data.input == 0)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
	}
	else
		write(1, " ", 1);
}