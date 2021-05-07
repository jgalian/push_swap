#include "header.h"

/*
** This function sends the last element to the top of the list so the first
** element will be second one
*/

void	ft_reverse_rotate(t_stack **head)
{
	t_stack	*tmp;

	if (!head || !(*head)->previous)
		return ;
	tmp = *head;
	while (tmp->previous != NULL)
		tmp = tmp->previous;
	tmp->previous = *head;
	*head = tmp;
	while (tmp->previous != *head)
		tmp = tmp->previous;
	tmp->previous = NULL;
}

void	ft_rra(t_all *all)
{
	ft_reverse_rotate(&all->a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_all *all)
{
	ft_reverse_rotate(&all->b);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_all *all)
{
	ft_reverse_rotate(&all->a);
	ft_reverse_rotate(&all->b);
	write(1, "rrr\n", 4);
}
