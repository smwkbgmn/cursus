int	ft_str_is_uppercase(char *str)
{
	int	moving;
	int	check;

	moving = 0;
	check = 0;

	while (str[moving])
	{
		if (str[moving] < 65 || str[moving] > 90)
			check ++;
		moving++;
	}

	if (check == 0)
		return (1);
	else
		return (0);
}
