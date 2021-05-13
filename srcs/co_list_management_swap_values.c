#include "header.h"

/*
** This function swaps first and second elements in the stack A if the first
** one is bigger
*/

void	ft_swap_a_if_bigger(t_all *all)
{
	if (all->a && all->a->prev && all->a->value > all->a->prev->value)
		ft_sa(all);
}

/*
** This function swaps first and second elements in the stack B if the first
** one is bigger
*/

void	ft_swap_b_if_bigger(t_all *all)
{
	if (all->b && all->b->prev && all->b->value > all->b->prev->value)
		ft_sb(all);
}

/*
** This function swaps first and second elements in the stack A if the first
** one is smaller
*/

void	ft_swap_a_if_smaller(t_all *all)
{
	if (all->a && all->a->prev && all->a->value < all->a->prev->value)
		ft_sa(all);
}

/*
** This function swaps first and second elements in the stack B if the first
** one is smaller
*/

void	ft_swap_b_if_smaller(t_all *all)
{
	if (all->b && all->b->prev && all->b->value < all->b->prev->value)
		ft_sb(all);
}
