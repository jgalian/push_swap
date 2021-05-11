#include "header.h"

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
	while (tmp->prev != NULL)
	{
		tmp = tmp->prev;
		i++;
	}
	return (i);
}

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
		node->prev = NULL;
	else
		node->prev = *head;
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
	else if (tmp->prev == NULL)
	{
		*head = NULL;
		free(tmp);
	}
	else
	{
		*head = tmp->prev;
		free(tmp);
	}
}

int		ft_is_stack_sorted(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp->prev)
	{
		if (tmp->value < tmp->prev->value)
			tmp = tmp->prev;
		else
			return (FALSE);
	}
	return (TRUE);
}
