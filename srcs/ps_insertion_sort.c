#include "header.h"

void	ft_insertion_sort_100(t_all *all)
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

void	ft_insertion_sort_500_a(t_all *all)
{
	int	n_elements;
	int	pos_smallest;
	int	rotations_smallest;
	int	pos_biggest;
	int	rotations_biggest;

	pos_smallest = ft_list_smallest_value_position(all->a);
	pos_biggest = ft_list_greatest_value_position(all->a);
	n_elements = ft_list_lenght(all->a);
	if (pos_smallest <= n_elements / 2)
		rotations_smallest = pos_smallest;
	else
		rotations_smallest = n_elements - pos_smallest;
	if (pos_biggest <= n_elements / 2)
		rotations_biggest = pos_biggest;
	else
		rotations_biggest = n_elements - pos_biggest;
	if (rotations_biggest < rotations_smallest)
		ft_exec_insert_sort_500_a_biggest(all, pos_biggest, rotations_biggest,
			n_elements);
	else
		ft_exec_insert_sort_500_a_smallest(all, pos_smallest,
			rotations_smallest, n_elements);
}

void	ft_exec_insert_sort_500_a_biggest(t_all *all, int pos_biggest,
	int rotations_biggest, int n_elements)
{
	if (pos_biggest <= n_elements / 2)
		while (rotations_biggest--)
			ft_ra(all);
	else
		while (rotations_biggest--)
			ft_rra(all);
	ft_pb(all);
	ft_rb(all);
}

void	ft_exec_insert_sort_500_a_smallest(t_all *all, int pos_smallest,
	int rotations_smallest, int n_elements)
{
	if (pos_smallest <= n_elements / 2)
		while (rotations_smallest--)
			ft_ra(all);
	else
		while (rotations_smallest--)
			ft_rra(all);
	ft_pb(all);
}
