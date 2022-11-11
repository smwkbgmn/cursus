/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   requirements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:01:53 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/05 17:15:50 by donghyu2         ###   ########.fr       */
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

	num = answ[r][c]; // 탐색을 하던 중 현재 가리키고 있는 칸을 필히 지나기 때문에 해당 값을 잠시 다른곳에 저장해둠
	answ[r][c] = 0; // 그 후 현재 가리키고 있는 칸에 0을 넣어줌 (자기 자신은 무조건 자기 자신과 값이 같이 때문에 탐색에 제외시키기 위해)
	idx = 0;
	while (idx < 4)
	{
		if (num == answ[r][idx] || num == answ[idx][c]) // 탐색 중 같은 값이 한곳이라도 만나면 바로 유효하지 않음으로 함수 종료
		{
			answ[r][c] = num;
			return (0);
		}
		idx++;
	}
	answ[r][c] = num; // 탐색이 끝날때까지 함수가 종료되지 않았다면, 이 말은 가리키고 있는 칸 외에는 해당 숫자가 없다는 뜻이므로 (즉, 해당 숫자는 현재 가리키고 있는 칸에만 있다는 뜻이므로) 유효함을 나타내는 1 반환
	return (1);
}

int	req_row_left(int **answ, int **input, int r)
{
	int	idx;
	int	hist; // 탐색 중 만난 가장 높은 값
	int	counter; // 몇개의 칸을 봤는지 저장할 변수 

	idx = 0;
	counter = 0;
	hist = answ[r][idx]; // 먼저 가장 첫번째 칸의 값을 가장 높은 값으로 넣어둠
	while (idx < 4)
	{
		if (answ[r][idx] == 0) // 초기값(=0)을 만나면 무조건 참으로 반환함 
			return (1);
		if (hist <= answ[r][idx]) // 현재까지의 가장 높은 값보다 더 높은 값을 만나게 될 경우
		{
			hist = answ[r][idx]; // 가장 높은 값을 방금 만난 값으로 변경시킨 후
			counter++; // 보게 된 칸 수를 하나 증가시킴
		}
		idx++;
	}
	if (counter == input[2][r]) // 탐색이 끝나고 보게 된 칸 수가 문제에 주어진 칸 수와 동일하다면 유효함으로 1 반환
		return (1);
	return (0); // 그렇지 않으면 0 반환
}

int	req_row_right(int **answ, int **input, int r)
{
	int	idx;
	int	hist;
	int	counter;

	idx = 3; // 이건 배열에 뒤쪽에서부터 앞쪽으로 탐색이 진행되기에, 배열의 끝을 가리키는 idx=3 을 넣어줌
	counter = 0; 
	hist = answ[r][idx]; // 역시나 가장 첫번째 칸의 값을 먼저 넣어줌
	while (idx >= 0) // 배열의 가장 앞까지 가야하기에 idx >= 0
	{
		if (answ[r][idx] == 0)
			return (1);
		if (hist <= answ[r][idx])
		{
			hist = answ[r][idx];
			counter++;
		}
		idx--; // 배열의 앞쪽으로 가야하기에 idx를 깎으며 진행
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
