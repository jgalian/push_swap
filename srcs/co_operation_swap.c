#include "header.h"

/*
** This function swaps first and second element in the list A
*/

void	ft_sa(t_all *all)
{
	int	top;
	int	second;

	top = ft_peek(all->a);
	ft_del_top(&all->a);
	second = ft_peek(all->a);
	ft_del_top(&all->a);
	ft_push_top(&all->a, top);
	ft_push_top(&all->a, second);
	write(1, "sa\n", 3);
}

/*
** This function swaps first and second element in the list B
*/

void	ft_sb(t_all *all)
{
	int	top;
	int	second;

	top = ft_peek(all->b);
	ft_del_top(&all->b);
	second = ft_peek(all->b);
	ft_del_top(&all->b);
	ft_push_top(&all->b, top);
	ft_push_top(&all->b, second);
	write(1, "sb\n", 3);
}

/*
** This function swaps first and second element in lists A and B
*/

void	ft_ss(t_all *all)
{
	ft_sa(all);
	ft_sb(all);
	write(1, "ss\n", 3);
}
