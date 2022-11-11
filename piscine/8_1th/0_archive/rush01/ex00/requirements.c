/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   requirements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:01:53 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/04 20:45:28 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_only_num(int **answ, int r, int c);
int	req_row_left(int **answ, int **input, int r);
int	req_row_right(int **answ, int **input, int r);
int	req_col_up(int **answ, int **input, int c);
int	req_col_down(int **answ, int **input, int c);

int	is_only_num(int **answ, int r, int c)
{
	int	idx;
	int	num;

	num = answ[r][c];
	answ[r][c] = 0;
	idx = 0;
	while (idx < 4)
	{
		if (num == answ[r][idx] || num == answ[idx][c])
		{
			answ[r][c] = num;
			return (0);
		}
		idx++;
	}
	answ[r][c] = num;
	return (1);
}

int	req_row_left(int **answ, int **input, int r)
{
	int	idx;
	int	hist;
	int	counter;

	idx = 0;
	counter = 0;
	hist = answ[r][idx];
	while (idx < 4)
	{
		if (answ[r][idx] == 0)
			return (1);
		if (hist <= answ[r][idx])
		{
			hist = answ[r][idx];
			counter++;
		}
		idx++;
	}
	if (counter == input[2][r])
		return (1);
	return (0);
}

int	req_row_right(int **answ, int **input, int r)
{
	int	idx;
	int	hist;
	int	counter;

	idx = 3;
	counter = 0;
	hist = answ[r][idx];
	while (idx >= 0)
	{
		if (answ[r][idx] == 0)
			return (1);
		if (hist <= answ[r][idx])
		{
			hist = answ[r][idx];
			counter++;
		}
		idx--;
	}
	if (counter == input[3][r])
		return (1);
	return (0);
}

int	req_col_up(int **answ, int **input, int c)
{
	int	idx;
	int	hist;
	int	counter;

	idx = 0;
	counter = 0;
	hist = answ[idx][c];
	while (idx < 4)
	{
		if (answ[idx][c] == 0)
			return (1);
		if (hist <= answ[idx][c])
		{
			hist = answ[idx][c];
			counter++;
		}
		idx++;
	}
	if (counter == input[0][c])
		return (1);
	return (0);
}

int	req_col_down(int **answ, int **input, int c)
{
	int	idx;
	int	hist;
	int	counter;

	idx = 3;
	counter = 0;
	hist = answ[idx][c];
	while (idx >= 0)
	{
		if (answ[idx][c] == 0)
			return (1);
		if (hist <= answ[idx][c])
		{
			hist = answ[idx][c];
			counter++;
		}
		idx--;
	}
	if (counter == input[1][c])
		return (1);
	return (0);
}
