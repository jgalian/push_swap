#include "header.h"

/*
** This function sends the last element to the top of the list so the first
** element becomes the second one
*/

void	ft_ch_reverse_rotate(t_stack **head)
{
	t_stack	*tmp;

	if (!head || !(*head)->prev)
		return ;
	tmp = *head;
	while (tmp->prev != NULL)
		tmp = tmp->prev;
	tmp->prev = *head;
	*head = tmp;
	while (tmp->prev != *head)
		tmp = tmp->prev;
	tmp->prev = NULL;
}

/*
** This function calls the reverse rotation function for stack A
*/

void	ft_ch_rra(t_all *all)
{
	ft_ch_reverse_rotate(&all->a);
	//write(1, "rra\n", 4);
}

/*
** This function calls the reverse rotation function for stack B
*/

void	ft_ch_rrb(t_all *all)
{
	ft_ch_reverse_rotate(&all->b);
	//write(1, "rrb\n", 4);
}

/*
** This function calls the reverse rotation function for both stack A and B
*/

void	ft_ch_rrr(t_all *all)
{
	ft_ch_reverse_rotate(&all->a);
	ft_ch_reverse_rotate(&all->b);
	//write(1, "rrr\n", 4);
}
