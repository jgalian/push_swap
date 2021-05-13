#include "header.h"

/*
** This function swaps first and second element in the list passed as argument
*/

void	ft_swap(t_stack *head)
{
	int	tmp;

	tmp = head->value;
	head->value = head->prev->value;
	head->prev->value = tmp;
}

/*
** This function swaps first and second element in list A
*/

void	ft_sa(t_all *all)
{
	ft_swap(all->a);
	write(1, "sa\n", 3);
}

/*
** This function swaps first and second element in list B
*/

void	ft_sb(t_all *all)
{
	ft_swap(all->b);
	write(1, "sb\n", 3);
}

/*
** This function swaps first and second element in lists A and B
*/

void	ft_ss(t_all *all)
{
	ft_swap(all->a);
	ft_swap(all->b);
	write(1, "ss\n", 3);
}
