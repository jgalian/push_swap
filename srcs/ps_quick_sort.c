#include "header.h"

void	ft_send_all_to_b(t_all *all)
{
	int i;
	int	average;
	int	n_elements;

	n_elements = ft_list_lenght(all->a);
	while (n_elements)
	{
		average = ft_list_values_average(all->a);
		i = -1;
		while (++i < n_elements)
		{
			//printf("average: %i\n", average);
			ft_swap_a_if_bigger(all);
			if (all->a->value <= average || !all->a->prev)
			{
				ft_pb(all);
				if (all->b && all->b->prev && all->b->value < all->b->prev->value)
				{
					if (all->a && all->a->prev && all->a->value > all->a->prev->value)
						ft_ss(all);
					else
				 		ft_sb(all);
				}
			}
			else
				ft_ra(all);
			//ft_print_all_lists(all);
		}
		n_elements = ft_list_lenght(all->a);
	}
}

void	ft_send_all_to_a(t_all *all)
{
	int 	i;
	int		average;
	int		n_elements;

	n_elements = ft_list_lenght(all->b);
	while (n_elements)
	{
		average = ft_list_values_average(all->b);
		i = -1;
		while (++i < n_elements)
		{
			//printf("average: %i\n", average);
			ft_swap_b_if_smaller(all);
			if (all->b->value >= average || !all->b->prev)
			{
				ft_pa(all);
				if (all->a && all->a->prev && all->a->value > all->a->prev->value)
				{
					if (all->b && all->b->prev && all->b->value < all->b->prev->value)
						ft_ss(all);
					else
						ft_sa(all);
				}
			}
			else
				ft_rb(all);
			//ft_print_all_lists(all);
		}
		n_elements = ft_list_lenght(all->b);
	}
}

int		ft_found_equal_or_smaller(t_stack *head, int num)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->value <= num)
			return (TRUE);
		tmp = tmp->prev;
	}
	return (FALSE);
}

int		ft_found_equal_or_bigger(t_stack *head, int num)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->value >= num)
			return (TRUE);
		tmp = tmp->prev;
	}
	return (FALSE);
}

void	ft_quick_sort_a(t_all *all)
{
	int	average;

	average = ft_list_values_average(all->a);
	while (ft_found_equal_or_smaller(all->a, average))
	{
		if (all->a->value <= average)// || !all->a->prev)
		{
			ft_pb(all);
			if (all->b->prev && all->b->value == ft_list_smallest_value(all->b))
			{
				if (all->a->value > average)
					ft_rr(all);
				else
					ft_rb(all);
			}
			if (all->b && all->b->prev && all->b->value < all->b->prev->value)// parece que da igual if que if else // igual se puede quitar all->b
			{
				if (all->a && all->a->prev && all->a->value > all->a->prev->value)//quiza se puede quitar all->a
					ft_ss(all);
				else
					ft_sb(all);
			}
		}
		else
			ft_ra(all);
	}
}

void	ft_quick_sort_b(t_all *all)
{
	int	average;

	average = ft_list_values_average(all->b);
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
			if (all->a && all->a->prev && all->a->value > all->a->prev->value)// parece que da igual if que if else // igual se puede quitar all->a
			{
				if (all->b && all->b->prev && all->b->value < all->b->prev->value)//igual se puede quitar all->b
					ft_ss(all);
				else
					ft_sa(all);
			}
		}
		else
			ft_rb(all);
		//ft_print_all_lists(all);
	}
}
