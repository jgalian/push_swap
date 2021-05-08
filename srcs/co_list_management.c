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

int		ft_list_smallest_value(t_stack *head)
{
	t_stack	*tmp;
	int		ret;

	tmp = head;
	ret = tmp->value;
	while (tmp->previous != NULL)
	{
		tmp = tmp->previous;
		if (tmp->value < ret)
			ret = tmp->value;
	}
	//printf("smallest: %i\n", ret);
	return (ret);
}

int		ft_list_greatest_value(t_stack *head)
{
	t_stack	*tmp;
	int		ret;

	tmp = head;
	ret = tmp->value;
	while (tmp->previous != NULL)
	{
		tmp = tmp->previous;
		if (tmp->value > ret)
			ret = tmp->value;
	}
	//printf("greatest: %i\n", ret);
	return (ret);
}

void	ft_swap_a_if_bigger(t_all *all)
{
	if (all->a && all->a->previous && all->a->value > all->a->previous->value)
		ft_sa(all);
}

void	ft_swap_b_if_bigger(t_all *all)
{
	if (all->b && all->b->previous && all->b->value > all->b->previous->value)
		ft_sb(all);
}

void	ft_swap_a_if_smaller(t_all *all)
{
	if (all->a && all->a->previous && all->a->value < all->a->previous->value)
		ft_sa(all);
}

void	ft_swap_b_if_smaller(t_all *all)
{
	if (all->b && all->b->previous && all->b->value < all->b->previous->value)
		ft_sb(all);
}

int		ft_list_values_average(t_stack *head)
{
	int	ret;

	ret = ft_list_values_sum(head) / ft_list_lenght(head);
	//printf("average: %i\n", ret);
	return (ret);

}

int		ft_list_values_sum(t_stack *head)
{
	t_stack	*tmp;
	int		ret;

	tmp = head;
	ret = tmp->value;
	while (tmp->previous != NULL)
	{
		tmp = tmp->previous;
		ret += tmp->value;
	}
	//printf("sum: %i\n", ret);
	return (ret);
}
