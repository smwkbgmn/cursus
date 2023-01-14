#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

long long* 	solution(long long numbers[], size_t numbers_len);
long long	find_next(long long n);

// int	main(void)
// {
// 	long long	numbers[1];
// 	size_t		len;
// 	long long	*result;
	
// 	numbers[0] = 238742;
// 	len = 1;
// 	result = solution(numbers, 1);
	
// 	printf("%lld\n", result[0]);

// 	return (0);
// }

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
