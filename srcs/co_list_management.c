#include "header.h"

/*
** This function insert one new element at the top of the list
*/

void	ft_push_top(t_stack **head, int value)
{
	t_stack	*node;

	if (!(node = (t_stack *)malloc(sizeof(t_stack))))
	{
		write(1, "Not able to push an element\n", 29);
		return ;
	}
	node->value = value;
	if (*head == NULL)
		node->previous = NULL;
	else
		node->previous = *head;
	*head = node;
}

/*
** This function get the first element out of the list
*/

void	ft_del_top(t_stack **head)
{
	t_stack	*tmp;

	tmp = *head;
	if (tmp == NULL)
		write(1, "Nothing to delete\n", 19);
	else if (tmp->previous == NULL)
	{
		*head = NULL;
		free(tmp);
	}
	else
	{
		*head = tmp->previous;
		free(tmp);
	}
}

/*
** This function prints out the values of all elements in the list
*/

void	ft_print_list(t_stack *head)
{
	t_stack	*current;

	if (!head)
		write(1, "List is empty\n", 15);
	else
	{
		current = head;
		while (current != NULL)
		{
			printf("%i / ", current->value);						//
			current = current->previous;
		}
		printf("\n");												//
	}
}

/*
** This function returns the value of the top element in the list
*/

int		ft_peek(t_stack *head)
{
	return (head->value);
}

/*
** This function returns the numbers of elements in the list
*/

int		ft_list_lenght(t_stack *head)
{
	t_stack	*tmp;
	int		i;

	if (head == NULL)
		return (0);
	tmp = head;
	i = 1;
	while (tmp->previous != NULL)
	{
		tmp = tmp->previous;
		i++;
	}
	return (i);
}

