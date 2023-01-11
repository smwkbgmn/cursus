long long	find_next(long long n);

long long* solution(long long numbers[], size_t numbers_len)
{
	long long	*result;
	size_t		idx;

	result = malloc(sizeof(long long) * numbers_len);
	idx = 0;
	while (idx < numbers_len)
		result[idx] = find_next(numbers[idx]);
	return (result);
}

long long	find_next(long long n)
{
	long long		next;
	long long		temp;
	long long		result1;
	long long		result2;
	long long		cnt1;
	long long		cnt2;

	if (n % 2 == 0)
		return (n + 1);
	next = n;
	while (1)
	{
		next++;
		temp = next;
		result1 = n & next;
		cnt2 = 0;
		while (temp > 0)
		{
			cnt2++;
			temp = temp >> 1;
		}
		cnt1 = 0;
		result1 = ~result1;
		while (cnt2 > 0)
		{
			result2 = result1 & 0b1;
			if (result2 == 0b1)
			{
				cnt1++;
			}
			result1 = result1 >> 1;
			cnt2--;
		}
		if (0 < cnt1 && cnt1 < 3)
			return (next);
	}
}
