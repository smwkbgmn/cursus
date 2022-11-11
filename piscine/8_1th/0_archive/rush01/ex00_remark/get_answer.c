/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_answer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:02:14 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/05 17:00:06 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		**ary_malloc(void); // 정답과 input을 담을 2차원 배열 공간 할당
void	answer_default(int **answer); // 정답 배열을 0으로 먼저 모두 채워줌
void	get_input_int(char *input, int	**input_int); // char형태로 들어온 문제를 int형태로 2차원 배열에 담아줌
void	finding(int	**answer, int **input_int); // 정답을 찾아서 배열에 답을 넣을 함수

int	**get_answer(char *input) 
{
	int	**answer;
	int	**input_int;
	int	idx_free;

	answer = ary_malloc(); // 공간 할당 
	input_int = ary_malloc(); // 공간 할당
	answer_default(answer); // 0으로 모두 채워줌
	get_input_int(input, input_int); // char 형태의 1차원 input 을 int 형태의 input 으로 새로 넣어줌
	finding(answer, input_int); // 정답 찾는 함수 
	idx_free = 0;
	while (idx_free < 4)
		free(input_int[idx_free++]); // Int 형태의 input 을 담고있던 배열 해제 
	free(input_int); // 머리 해제
	return (answer); // 정답 2차원 배열을 main 함수에 넘겨줌
}

int	**ary_malloc(void)
{
	int	**array;
	int	idx;

	array = (int **)malloc(4 * sizeof(int *)); // 행의 개수만큼 공간 할당
	if (array == 0)
		return ((void *) 0);
	idx = 0;
	while (idx < 4)
	{
		array[idx] = (int *)malloc(4 * sizeof(int)); // 열의 개수만큼의 공간을 총 4번 할당
		if (array[idx] == 0)
			return ((void *)0);
		idx++;
	}
	return (array); // 할당이 완료된 배열의 메모리 주소를 넘겨줌
}

void	answer_default(int **answer)
{
	int	r;
	int	c;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			answer[r][c] = 0; 
			c++;
		}
		r++;
	}
}

void	get_input_int(char *input, int	**input_int)
{
	int	r;
	int	c;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4 && *input)
		{
			if ('0' <= *input && *input <= '9') // char 형태의 '숫자'들을
			{
				input_int[r][c] = *input - '0'; // int 형태의 '수'로 바꿔서 저장함
				c++;
			}
			input++;
		}
		r++;
	}
}
