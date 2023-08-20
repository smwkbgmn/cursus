#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

#define OFFSET 70000

void	suspend(long long microsec);

int	main(void)
{
	struct timeval	start;
	struct timeval	now;
	struct timeval	elap;
	long			cnt;
	long long		sum;

	gettimeofday(&start, NULL);
	cnt = 0;
	sum = 0;
	while (cnt < 30)
	{
		// suspend(1000);
		// usleep(500);
		suspend(70000);
		gettimeofday(&now, NULL);

		elap.tv_usec = now.tv_usec - start.tv_usec;
		printf("start %d, now %d / ", start.tv_usec, now.tv_usec);
		printf("milisec %d\n", elap.tv_usec);
		if (elap.tv_usec > 0)
		{
			sum += elap.tv_usec;
			cnt++;
		}
		start.tv_usec = now.tv_usec;
	}
	printf("maen : %lld\n", sum / 30);
}

void	suspend(long long microsec)
{
	if (microsec <= OFFSET)
		usleep(microsec);
	else
	{
		usleep(OFFSET);
		suspend(microsec - OFFSET);
	}
}
