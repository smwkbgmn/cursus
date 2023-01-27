#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int		check[100000];
char	ch[100000];
int		most_num = 0;
int		max = 0;

char* solution(const char* number, int k)
{    
    // char* ans = (char*)calloc(front, 1);
    
    int len = strlen(number);
    int front = len - k; // 앞자리를 구하려고 이렇게 구함!!
    int max = 0;
    int idx = 0;
    
    for (int i=0; i < front; i++)
    {
        if (number[i] - '0' > max)
        {
            max = number[i] -'0';
            idx = i;
            check[0] = max; //제일 큰 수가 앞으로 올 수 있게끔 하려고
        }
    }

    int k_cnt = idx;
    int ch = 1;
    char cpy[1000000];
    strcpy(cpy, number);
    printf("ch front: %d\n", check[0]);

    rec(1, cpy, len, idx, front);

    printf("max : %d\n", max);
    return "1";
}

void rec(int one, char num[], int len,  int idx, int front)
{
    int save = one;
//탈출 조건은 index가 front만큼 왔을 때. 자릿수가 같아지는 거니까 이렇게 설정함!
    if (one == front)
    {
        int most_num = check[0]; //아까 저장해논 가장 큰수 (앞자리)를 가져와서
        for(int i=idx+1; i < len; i++)
            most_num = 10 * most_num + (ch[i] - '0'); //요기따 넣고 계산 돌림..내가 원하는 건 3123, 3124, 이렇게 쭉 들어오는것..ㅠㅠ 
        if (max < most_num)
            max = most_num; //max에 most_num넣어줌..
        return ;
    }

    for(int i=idx + 1; i<len; i++)
    {
        ch[one] = num[i];
        rec(one+1, num, len, idx, front);
        ch[save] = num[i]; //이부분이 해괴망측함...
    }
}



// #include <stdlib.h>
// #include <string.h>

// #define NUM(c) c - '0'

// short	is_largest(const char *number, int len_rest);

// char	*solution(const char *number, int k)
// {
//     char	*result;
// 	int		len;
// 	int		idx;

// 	len = strlen(number) - k;
// 	result = malloc(len + 1);
// 	result[len] = 0;
// 	idx = 0;
// 	while (idx < len)
// 	{
// 		if (is_largest(number, len - idx))
// 			result[idx++] = *number;
// 		number++;
// 	}
//     return (result);
// }

// short	is_largest(const char *number, int len_rest)
// {
// 	int	num;

// 	num = NUM(*number);
// 	while (*(number + len_rest))
// 	{
// 		if (num < NUM(*++number))
// 			return (0);
// 	}
// 	return (1);
// }

#include <stdio.h>

int	main(void)
{
	char	n[20] = "4177252841";

	printf("input\t--- [%s]\n", n);
	printf("output\t--- [%s]\n", solution(n, 4));

	return (0);
}
