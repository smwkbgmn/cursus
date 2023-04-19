/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_meadian.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:42:25 by donghyu2          #+#    #+#             */
/*   Updated: 2023/04/01 19:39:08 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/////// TEMPORARY TIM_SORT ALGORITHM
/////// FOR FINDING MEADIAN VALUE
/////// Implement later ! 

#include <stdio.h>
#include <stdlib.h>

#include "push_swap.h"

// Define the minimum size of a subarray to be merged
const int MIN_MERGE = 32;

// Function to perform insertion sort on a sublist
void insertion_sort(int arr[], int start, int end) {
    for (int i = start + 1; i <= end; i++) {
        int current = arr[i];
        int j = i - 1;

        while (j >= start && arr[j] > current) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = current;
    }
}

// Function to merge two sworted subarrays
void merge(int arr[], int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int left[n1], right[n2];

    for (int i = 0; i < n1; i++) {
        left[i] = arr[start + i];
    }

    for (int i = 0; i < n2; i++) {
        right[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = start;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < n1) {
        arr[k++] = left[i++];
    }

    while (j < n2) {
        arr[k++] = right[j++];
    }
}

// Function to perform Tim Sort
void tim_sort(int arr[], int n) {
    int min_run = MIN_MERGE;

    for (int i = 0; i < n; i += min_run) {
        insertion_sort(arr, i, (i + min_run - 1 < n - 1) ? i + min_run - 1 : n - 1);
    }

    for (int size = min_run; size < n; size = 2 * size)
    {
        for (int left = 0; left < n; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = (left + 2 * size - 1 < n - 1) ? left + 2 * size - 1 : n - 1;

            merge(arr, left, mid, right);
        }
		printf("check here\n");
    }
}

int	*init_array(int size, char **av)
{
	int	*ary;
	int	idx;

	ary = malloc(sizeof(int) * size);
	idx = 0;
	while (av[idx])
	{
		ary[idx] = ft_atoi(av[idx]);
		idx++;
	}
	return (ary);
}

int	find_meadian(int ac, char **av)
{
	int	*ary;
	int	size;
	int	idx;

	size = ac - 1;
	ary = init_array(size, av);
	tim_sort(ary, size);
	printf("\n[[sorted]]\n");
	idx = 0;
	while (idx < size)
		printf("[%d]", ary[idx++]);
	printf("\n");
	printf("\nmeadian --- %d\n", ary[size / 2]);
	return (ary[size / 2]);
}
