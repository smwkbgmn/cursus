/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:57:18 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/05 17:08:10 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_answer(int **answ, int **input, int *r_c, int *vald); // 특정 칸의 값을 바꾼 후 조건에 맞는지 체크 
int		check_available(int **answ, int **input, int *r_c); // 총 5가지의 조건에 부합하는지 확인. 모두 맞으면 1, 한개라도 안맞으면 0.
int		is_only_num(int **answ, int r, int c); // 현재 가리키는 칸에 있는 숫자가, 속해있는 행과 열중에 해당 칸에만 있으면 1, 다른 칸에도 있으면 0.
int		req_row_left(int **answ, int **input, int r); // 좌측 조건 확인. 충족하면 1, 아니면 0.
int		req_row_right(int **answ, int **input, int r); // 우측 조건 확인
int		req_col_up(int **answ, int **input, int c); // 위쪽 조건 확인
int		req_col_down(int **answ, int **input, int c); // 아래쪽 조건 확인

void	finding(int **answ, int **input)
{
	int	r_c[2]; // r_c[0] = 행, r_c[1] = 열
	int	vald; // 조건을 모두 충족한 상태인지 아닌지를 담고있을 int 변수. 모두 충족하면 1, 아니면 0.

	r_c[0] = 0;
	vald = 1; // 먼저 모두 충족한 상태로 while에 들어감
	while (0 <= r_c[0] && r_c[0] < 4)
	{
		if (vald == 1) // 조건을 충족하면 다음 행의 첫번째 열
			r_c[1] = 0; 
		else // 충족하지 못하면 이전 행의 마지막 열
			r_c[1] = 3;
		while (0 <= r_c[1] && r_c[1] < 4)
		{
			fill_answer(answ, input, r_c, &vald);
			if (vald == 1) // 조건을 충족하면 다음 열
				r_c[1]++;
			else // 충족하지 못하면 이전 열
				answ[r_c[0]][r_c[1]--] = 0;
		}
		if (vald == 1) // 조건을 충족하면 다음 행
			r_c[0]++;
		else // 충족하지 못하면 이전 행
			r_c[0]--;
	}
}

void	fill_answer(int **answ, int **input, int *r_c, int *vald)
{
	answ[r_c[0]][r_c[1]]++; // 해당 칸의 값을 1 올림
	if (answ[r_c[0]][r_c[1]] > 4) // 칸의 값이 5가 되면 종료시킴
		return ;
	*vald = check_available(answ, input, r_c); // 조건이 모두 충족되면 vald = 1, 그렇지 않으면 vald = 0
	if (*vald == 1) // 조건이 충족되었으면 다음 열로 가기 위해 종료
		return ;
	else // 조건이 만족되지 않으면 기능을 한번 더 실행시킴 (즉, 값을 1 올린 후 조건 다시 체크)
		fill_answer(answ, input, r_c, vald);
}

int	check_available(int **answ, int **input, int *r_c) // 5가지 조건을 체크 
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
