#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

long long* 	solution(long long numbers[], size_t numbers_len);
long long	find_next(long long n);

int	main(void)
{
	long long	numbers[1];
	size_t		len;
	long long	*result;
	
	numbers[0] = 238742;
	len = 1;
	result = solution(numbers, 1);
	
	printf("%lld\n", result[0]);

	return (0);
}

long long	*solution(long long numbers[], size_t numbers_len)
{
	long long	*result;
	size_t		idx;

	result = malloc(sizeof(long long) * numbers_len);
	idx = 0;
	while (idx < numbers_len)
	{
		result[idx] = find_next(numbers[idx]);
		idx++;
	}
	return (result);
}

long long	find_next(long long n)
{
	long long	bin;

	if ((n & 1) == 0)
		return (n + 1);
	bin = 1;
	while ((n & bin) != 0)
		bin <<= 1;
	n = n | bin;
	bin >>= 1;
	n = n ^ bin;
	return (n);
}

// long long	find_next(long long n)
// {
// 	long long		next;
// 	long long		temp;
// 	long long		result;
// 	long long		cnt;
// 	long long		len;

// 	temp = n & 0b1;
// 	if (temp == 0b0)
// 		return (n + 1);
// 	next = n;
// 	while (1)
// 	{
// 		next++;
// 		temp = next;
// 		result = n ^ next;
// 		len = 0;
// 		while (temp > 0)
// 		{
// 			len++;
// 			temp = temp >> 1;
// 		}
// 		printf("where am I? next, len --- [%lld][%lld]\n", next, len);
// 		cnt = 0;
// 		// result = ~result;
// 		while (len > 0)
// 		{
// 			printf("%lld", cnt);
// 			temp = result & 0b1;
// 			if (temp == 0b1)
// 				cnt++;
// 			if (cnt > 2)
// 				break ;
// 			result = result >> 1;
// 			len--;
// 		}
// 		printf("\n");
// 		if (0 < cnt && cnt < 3)
// 			return (next);
// 	}
// }
