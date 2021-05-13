#include "header.h"

void	ft_insertion_sort_a(t_all *all)
{
	int	n_elements;
	int	position;
	int	middle;
	int	rotations;

	position = ft_list_smallest_value_position(all->a);
	n_elements = ft_list_lenght(all->a);
	middle = n_elements / 2;
	if (position <= middle)
		rotations = position;
	else
		rotations = n_elements - position;
	if (position <= middle)
		while (rotations--)
			ft_ra(all);
	else
		while (rotations--)
			ft_rra(all);
	ft_pb(all);
}

void	ft_insertion_sort_b(t_all *all)
{
	int	n_elements;
	int	position;
	int	middle;
	int	rotations;

	position = ft_list_greatest_value_position(all->b);
	n_elements = ft_list_lenght(all->b);
	middle = n_elements / 2;
	if (position <= middle)
		rotations = position;
	else
		rotations = n_elements - position;
	if (position <= middle)
		while (rotations--)
			ft_rb(all);
	else
		while (rotations--)
			ft_rrb(all);
	ft_pa(all);
}
