/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:30:39 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/05 16:53:33 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	**get_answer(char *input);

int	check_value(int idx, char **argv)
{
	if (idx != 2)
		return (1); // 인자가 정확히 1개 들어왔을때만 유효
	idx = 0;
	while (argv[1][idx])
		idx++;
	if (idx != 31) // input 길이가 정확히 31일때만 유효
		return (1);
	idx = 0;
	while (idx <= 30)
	{
		if (!(argv[1][idx] >= '1' && argv[1][idx] <= '4')) // 숫자 자리에 숫자만 있어야 유효 
			return (1);
		idx += 2; // 숫자 사이사이 공백이 있기에 2씩 올라감
	}
	idx = 1;
	while (idx <= 29)
	{
		if (argv[1][idx] != ' ') // 숫자 사이사이가 공백일때만 유효
			return (1);
		idx += 2;
	}
	return (0);
}

int	check_input(char **argv) // 양 끝의 조건값이 더했을때 3~5일때만 유효
{
	int		col;
	int		row;
	char	num1;
	char	num2;

	col = 0;
	row = 16;
	while (col <= 6)
	{
		num1 = argv[1][col] + argv[1][col + 8] - '0';
		if (!(num1 >= '3' && num1 <= '5'))
			return (1);
		num2 = argv[1][row] + argv[1][row + 8] - '0';
		if (!(num2 >= '3' && num2 <= '5'))
			return (1);
		row += 2;
		col += 2;
	}
	return (0);
}

void	char_in_arr(char **argv, char *str) // input에 있는 공백을 지우고 숫자만 남기고 새로운 배열어 넣어둠
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (k < 16)
	{
		str[k] = argv[1][i];
		k++;
		i += 2;
	}
	return ;
}

void	print(int **answer) // 정답 도출이 끝나고 정답이 들어있는 테이블을 출력함
{
	int	r;
	int	c;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			write(1, &"01234"[answer[r][c]], 1);
			if (c < 3)
				write(1, " ", 1);
			c++;
		}
		write(1, "\n", 1);
		r++;
	}
}

int	main(int argc, char *argv[])
{
	int		**answer;
	int		idx_free;
	char	*str;

	if (check_value(argc, argv) || check_input(argv)) // input 값이 유효하지 않으면 Error
	{
		write(1, "Error\n", 6);
		return (0);
	}
	str = (char *)malloc(sizeof(char) * 17); // input에서 공백을 지우고 숫자만 담을 새로운 배열 할당
	char_in_arr(argv, str); // 공백을 지우고 숫자만 담는 기능을 하는 함수
	answer = get_answer(str); // 답을 도출하여 2차원 배열에 담는 기능을 함수
	if (answer[3][3] == 0)
		write(1, "Error\n", 6); // 답이 나오지 않는 input일 경우 Error 출력
	else
		print(answer); // 그 외에 답이 나온 input이면 출력함
	free(str); // input을 담았던 배열 메모리 해제
	idx_free = 0;
	while (idx_free < 4)
		free(answer[idx_free++]); // 정답을 담았던 1행~4행 메모리 해제
	free(answer); // 정답을 담았던 머리에 해당하는 부분 해제
	return (0);
}
