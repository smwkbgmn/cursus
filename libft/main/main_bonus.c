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

int main(void)
{
	t_list *head;
	t_list *last;
	int data[20];
	int n;


	FILLN(20);
	head = ft_lstnew(&data[0]);

	n = 1;
	while (n < 5)
		ft_lstadd_front(&head, ft_lstnew(&data[n++]));

	while (n < 10)
		ft_lstadd_back(&head, ft_lstnew(&data[n++]));

	



	print_lst(head);
	
	printf("list length --- [%d]\n", ft_lstsize(head));

	last = ft_lstlast(head);
	printf("the value of last of the link --- [%d]\n", *(int *)last->content);
}

void print_lst(t_list *head)
{
	while (head)
	{
		printf("[%d]", *(int *)head->content);
		head = head->next;
	}
	printf("\n");
}