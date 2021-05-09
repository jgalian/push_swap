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
			current = current->prev;
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
	while (tmp->prev != NULL)//quizas es mejor tmp != NULL
	{
		tmp = tmp->prev;
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
	while (tmp->prev != NULL)//quizas es mejor tmp != NULL
	{
		tmp = tmp->prev;
		if (tmp->value < ret)
			ret = tmp->value;
	}
	//printf("smallest: %i\n", ret);
	return (ret);
}

int		ft_list_smallest_value_position(t_stack *head)
{
	t_stack	*tmp;
	int		smallest;
	int		position;
	int		i;

	tmp = head;
	smallest = tmp->value;
	position = 0;
	i = 0;
	while (tmp->prev != NULL)//quizas es mejor tmp != NULL
	{
		i++;
		tmp = tmp->prev;
		if (tmp->value < smallest)
		{
			smallest = tmp->value;
			position = i;
		}
	}
	//printf("smallest_value_position: %i\n", ret);
	return (position);
}

int		ft_list_greatest_value(t_stack *head)
{
	t_stack	*tmp;
	int		ret;

	tmp = head;
	ret = tmp->value;
	while (tmp->prev != NULL)//quizas es mejor tmp != NULL
	{
		tmp = tmp->prev;
		if (tmp->value > ret)
			ret = tmp->value;
	}
	//printf("greatest: %i\n", ret);
	return (ret);
}

int		ft_list_greatest_value_position(t_stack *head)
{
	t_stack	*tmp;
	int		greatest;
	int		position;
	int		i;

	tmp = head;
	greatest = tmp->value;
	position = 0;
	i = 0;
	while (tmp->prev != NULL)//quizas es mejor tmp != NULL
	{
		i++;
		tmp = tmp->prev;
		if (tmp->value > greatest)
		{
			greatest = tmp->value;
			position = i;
		}
	}
	//printf("smallest_value_position: %i\n", ret);
	return (position);
}

void	ft_swap_a_if_bigger(t_all *all)
{
	if (all->a && all->a->prev && all->a->value > all->a->prev->value)
		ft_sa(all);
}

void	ft_swap_b_if_bigger(t_all *all)
{
	if (all->b && all->b->prev && all->b->value > all->b->prev->value)
		ft_sb(all);
}

void	ft_swap_a_if_smaller(t_all *all)
{
	if (all->a && all->a->prev && all->a->value < all->a->prev->value)
		ft_sa(all);
}

void	ft_swap_b_if_smaller(t_all *all)
{
	if (all->b && all->b->prev && all->b->value < all->b->prev->value)
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

	if (!head)
		return (0);
	tmp = head;
	ret = tmp->value;
	while (tmp->prev != NULL)
	{
		tmp = tmp->prev;
		ret += tmp->value;
	}
	//printf("sum: %i\n", ret);
	return (ret);
}
