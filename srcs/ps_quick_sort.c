#include "header.h"

void	ft_quick_sort_stack_a(t_all *all, int average)
{
	while (ft_found_equal_or_smaller(all->a, average))
	{
		if (all->a->value <= average)
		{
			ft_pb(all);
			if (all->b->prev && all->b->value == ft_list_smallest_value(all->b))
			{
				if (all->a->value > average)
					ft_rr(all);
				else
					ft_rb(all);
			}
			if (all->b->prev && all->b->value < all->b->prev->value)
			{
				if (all->a->prev && all->a->value > all->a->prev->value)
					ft_ss(all);
				else
					ft_sb(all);
			}
		}
		else
			ft_ra(all);
	}
}

void	ft_quick_sort_stack_b(t_all *all, int average)
{
	while (ft_found_equal_or_bigger(all->b, average))
	{
		if (all->b->value >= average || !all->b->prev)
		{
			ft_pa(all);
			if (all->a->prev && all->a->value == ft_list_greatest_value(all->a))
			{
				if (all->b->value < average)
					ft_rr(all);
				else
					ft_ra(all);
			}
			if (all->a->prev && all->a->value > all->a->prev->value)
			{
				if (all->b->prev && all->b->value < all->b->prev->value)
					ft_ss(all);
				else
					ft_sa(all);
			}
		}
		else
			ft_rb(all);
	}
}
