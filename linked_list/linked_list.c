#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int data;
	struct s_node *next;
}	t_node;

void push1(t_node **head, int data);
t_node *push2(t_node *head, int data);
void insert(t_node *prev, int data);
void append(t_node **head, int data);
void remove_if(t_node **head, int data);
void print(t_node *head);

int main(void)
{
	t_node *head;

	head = 0; // 'head' has the address of a node that is reffering a begining of the linked list
	
	// 'push' : add a new node to a front of 'head' node
	push1(&head, 10); // option 1
	head = push2(head, 10); // option 2

	// 'insert' : add a new node to the front of a specified node 
	insert(head->next, 15);

	// 'append' : add a new node to the tail of the linked list
	append(&head, 20); 
	
	// 'remove_if' : remove all node that is match with the input data 
	remove_if(&head, 15);
	
	print(head);
}

// option 1 : using double pointer of 'head', so it dosen't need to return
void push1(t_node **head, int data)
{
	t_node *new;

	new = malloc(sizeof(t_node));
	new->data = data;
	new->next = *head;
	*head = new;
}

// option 2 : more simpler, but need to return a new node
t_node *push2(t_node *head, int data)
{
	t_node *new;

	new = malloc(sizeof(t_node));
	new->data = data;
	new->next = head;
	return (new);
}

void insert(t_node *prev, int data)
{
	t_node *new;

	if (prev == 0)
		return ;
	
	new = malloc(sizeof(t_node));
	new->data = data;
	new->next = prev->next;
	prev->next = new;
}

void append(t_node **head, int data)
{
	t_node *new;
	t_node *tail;

	new = malloc(sizeof(t_node));
	new->data = data;
	new->next = 0;
	if (head == 0)
	{
		*head = new;
		return ;
	}
	tail = *head;
	while (tail->next)
		tail = tail->next;
	tail->next = new;
}

void remove_if(t_node **head, int data)
{
	t_node *idx;
	t_node *tmp;

	while ((*head)->data == data && *head)
	{
		tmp = *head;
		*head = (*head)->next; 
		free(tmp);
	}
	// aware that head could be pointing a null after prior while  
	idx = *head;
	while (idx && idx->next)
	{
		if (idx->next->data == data)
		{
			tmp = idx->next;
			idx->next = idx->next->next;
			free(tmp);
		}
		else
			idx = idx->next;
	}
}

void print(t_node *head)
{
	while (head)
	{
		printf("[%d]", head->data);
		head = head->next;
	}
}
