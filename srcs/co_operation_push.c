#include "header.h"

/*
** This function pushses a new element at the top of list A
*/

void	ft_pa(t_all *all)
{
	int	n;

	if (all->b)
	{
		n = ft_peek(all->b);
		ft_del_top(&all->b);
		ft_push_top(&all->a, n);
	}
}

/*
** This function pushses a new element at the top of list B
*/

void	ft_pb(t_all *all)
{
	int	n;

	if (all->a)
	{
		n = ft_peek(all->a);
		ft_del_top(&all->a);
		ft_push_top(&all->b, n);
	}
}
