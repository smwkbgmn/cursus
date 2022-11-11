/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:57:18 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/04 21:18:06 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_answer(int **answ, int **input, int *r_c, int *vald);
int		check_available(int **answ, int **input, int *r_c);
int		is_only_num(int **answ, int r, int c);
int		req_row_left(int **answ, int **input, int r);
int		req_row_right(int **answ, int **input, int r);
int		req_col_up(int **answ, int **input, int c);
int		req_col_down(int **answ, int **input, int c);

void	finding(int **answ, int **input)
{
	int	r_c[2];
	int	vald;

	r_c[0] = 0;
	vald = 1;
	while (0 <= r_c[0] && r_c[0] < 4)
	{
		if (vald == 1)
			r_c[1] = 0;
		else
			r_c[1] = 3;
		while (0 <= r_c[1] && r_c[1] < 4)
		{
			fill_answer(answ, input, r_c, &vald);
			if (vald == 1)
				r_c[1]++;
			else
				answ[r_c[0]][r_c[1]--] = 0;
		}
		if (vald == 1)
			r_c[0]++;
		else
			r_c[0]--;
	}
}

void	fill_answer(int **answ, int **input, int *r_c, int *vald)
{
	answ[r_c[0]][r_c[1]]++;
	if (answ[r_c[0]][r_c[1]] > 4)
		return ;
	*vald = check_available(answ, input, r_c);
	if (*vald == 1)
		return ;
	else
		fill_answer(answ, input, r_c, vald);
}

int	check_available(int **answ, int **input, int *r_c)
{
	if (is_only_num(answ, r_c[0], r_c[1]) == 0)
		return (0);
	if (req_row_left(answ, input, r_c[0]) == 0)
		return (0);
	if (req_row_right(answ, input, r_c[0]) == 0)
		return (0);
	if (req_col_up(answ, input, r_c[1]) == 0)
		return (0);
	if (req_col_down(answ, input, r_c[1]) == 0)
		return (0);
	return (1);
}
