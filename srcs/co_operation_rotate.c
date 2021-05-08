#include "header.h"

/*
** This function sends the first element to the end of the list so the second
** element will be the top one
*/

void	ft_rotate(t_stack **head)
{
	t_stack	*tmp;

	if (!head || !(*head)->previous)
		return ;
	tmp = *head;
	while (tmp->previous != NULL)
		tmp = tmp->previous;
	tmp->previous = *head;
	tmp = tmp->previous;
	*head = tmp->previous;
	tmp->previous = NULL;
}

void	ft_ra(t_all *all)
{
	ft_rotate(&all->a);
	write(1, "ra\n", 3);
}

void	ft_rb(t_all *all)
{
	ft_rotate(&all->b);
	write(1, "rb\n", 3);
}

void	ft_rr(t_all *all)
{
	ft_rotate(&all->a);
	ft_rotate(&all->b);
	write(1, "rr\n", 3);
}
