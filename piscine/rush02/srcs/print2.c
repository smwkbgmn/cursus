#include "rush.h"

void hundred(t_data *data, int *idx)
{
	one(data, idx);
	if (print_number(*data) != 1)
	{
		*idx = -42;
		return ;
	}
	write(1, " ", 1);

	init_buffer(data->to_find);
	ft_strcpy(data->to_find, "100:");
}

void ten(t_data *data, int *idx)
{
	if (data->input[*idx] == '1')
	{
		data->to_find[0] = data->input[*idx];
		data->to_find[1] = data->input[*idx + 1];
		*idx += 1;
	}
	else
	{
		data->to_find[0] = data->input[*idx];
		data->to_find[1] = '0';
	}
	ft_strcat(data->to_find, ":");
}

void one(t_data *data, int *idx)
{
	data->to_find[0] = data->input[*idx];
	data->to_find[1] = ':';
}

void unit(t_data *data, int *idx)
{
	int	zero;

	init_buffer(data->to_find);
	data->to_find[0] = '1';

	zero = data->len - *idx;
	while (--zero > 0)
		ft_strcat(data->to_find, "0");

	ft_strcat(data->to_find, ":");

	if (print_number(*data) != 1)
	{
		*idx = -42;
		return ;
	}
	print_sep(*data, *idx + 1);
}