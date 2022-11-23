#include "main.h"

#define FILLN(n) \
{ \
	size_t idx = 0; \
	while (idx < n) \
	{ \
		data[idx] = idx; \
		idx++; \
	} \
} 

void print_lst(t_list *node);
void del(void *content);
void *make_number_negative(void *number);

int main(void)
{
	t_list *head;
	t_list *last;
	int data[20];
	int n;

	// fill data with numbers ascending order 
	FILLN(20);

	// allocate a node as the head node
	head = ft_lstnew(&data[0]);

	// add three nodes to the front of the head node
	n = 1;
	while (n < 3)
		ft_lstadd_front(&head, ft_lstnew(&data[n++]));

	// add three nodes to the back of the head node
	while (n < 6)
		ft_lstadd_back(&head, ft_lstnew(&data[n++]));

	// printf the list
	printf("test list 1\n");
	print_lst(head);
	printf("\n");

	// print size of the list
	printf("length of test list 1 --- [%d]\n", ft_lstsize(head));
	
	// assign a last node to the 'last' and print a node pointed by 'last' 
	last = ft_lstlast(head);
	printf("the last value of test list 1 --- [%d]\n", *(int *)last->content);
	printf("\n");

	// declare ptr 'head_mapped' 
	t_list *head_mapped;

	// assign a head node of a list that is created with the function 'ft_lstmap'
	head_mapped = ft_lstmap(head, &make_number_negative, &del);

	// print the list
	printf("mapped test list 1\n");
	print_lst(head_mapped);
	printf("\n");

	//////////////////////////////////////////////////////////////

	int *foo1 = malloc(sizeof(t_list));
	int *foo2 = malloc(sizeof(t_list));
	int *foo3 = malloc(sizeof(t_list));
	int *foo4 = malloc(sizeof(t_list));
	int *foo5 = malloc(sizeof(t_list));

	*foo1 = 0;
	t_list *test2_head = ft_lstnew(foo1);

	*foo2 = 1;
	ft_lstadd_back(&test2_head, ft_lstnew(foo2));

	*foo3 = 2;
	ft_lstadd_back(&test2_head, ft_lstnew(foo3));

	*foo4 = 3;
	ft_lstadd_back(&test2_head, ft_lstnew(foo4));

	*foo5 = 4;
	ft_lstadd_back(&test2_head, ft_lstnew(foo5));


	printf("test list 2\n");
	print_lst(test2_head);
	printf("\n");

	t_list *test2_last = ft_lstlast(test2_head);

	printf("after ft_lstdelone to last node of the test list 2\n");
	ft_lstdelone(test2_last, &del);
	n = 4;
	while (n-- > 0)
	{
		printf("[%d]", *(int *)test2_head->content);	
		test2_head = test2_head->next;
	}
	printf("\n\n");

	///////////////////////////////////////////////////////////

	int *bar1 = malloc(sizeof(t_list));
	int *bar2 = malloc(sizeof(t_list));
	int *bar3 = malloc(sizeof(t_list));
	int *bar4 = malloc(sizeof(t_list));
	int *bar5 = malloc(sizeof(t_list));

	*bar1 = 0;
	t_list *test3_head = ft_lstnew(bar1);

	*bar2 = 1;
	ft_lstadd_back(&test3_head, ft_lstnew(bar2));

	*bar3 = 2;
	ft_lstadd_back(&test3_head, ft_lstnew(bar3));

	*bar4 = 3;
	ft_lstadd_back(&test3_head, ft_lstnew(bar4));

	*bar5 = 4;
	ft_lstadd_back(&test3_head, ft_lstnew(bar5));


	printf("test list 3\n");
	print_lst(test3_head);
	printf("\n");

	// delete whole test list 3 and try to print 
	printf("after ft_lstclear try to print test list 3\n");
	ft_lstclear(&test3_head, &del);
	print_lst(test3_head);
	printf("\n");
}

void print_lst(t_list *head)
{
	if (!head)
		printf("there is nothing to print at all");

	while (1)
	{
		if (!head)
			break;
		printf("[%d]", *(int *)head->content);
		if (head->next == 0)
			break;
		else
			head = head->next;
	}
	printf("\n");
}

void del(void *content)
{
	free(content);
}

void *make_number_negative(void *number)
{
	*(int *)number *= -1;
	return (number);
}

