#include "header.h"

/*
** Push_swap program should receive as argument a list of integers. It has to
** fill the stack A with theese numbers. And then, using a limited type of
** instructions, with help of stack B (empty at the begining), get them sorted
** with the smallest number at the top of stack A. It should use the smallest
** list of instructions possible.
*/

int	main(int argc, char **argv)
{
	t_all	*all;
	int		n_elements;

	if (argc != 2)
		return (1);
	all = (t_all *)malloc(sizeof(t_all));
	if (!all)
		ft_error();
	all->a = NULL;
	all->b = NULL;
	ft_set_initial_stack(&all->a, argv);
	n_elements = ft_list_lenght(all->a);
	if (!n_elements)
		return (1);
	else if (n_elements <= 4)
		ft_ps_3(all, n_elements);
	else if (n_elements > 4 && n_elements < 50)
		ft_ps_5(all, n_elements);
	else
		ft_ps_big(all, n_elements);
	ft_clean_up(all);
	return (0);
}

void	ft_ps_3(t_all *all, int n_elements)
{
	if (n_elements == 1)
		return ;
	else if (n_elements == 2)
	{
		if (!ft_is_stack_sorted(all->a))
			ft_sa(all);
	}
	else if (n_elements == 3)
	{
		if (ft_list_smallest_value_position(all->a) == 0)
			ft_ra(all);
		else if (ft_list_smallest_value_position(all->a) == 1)
			ft_rra(all);
		if (all->a->value > all->a->prev->value)
			ft_sa(all);
		ft_rra(all);
	}
	else
	{
		while (all->a)
			ft_insertion_sort_a(all);
		while (all->b)
			ft_pa(all);
	}
}

void	ft_ps_5(t_all *all, int n_elements)
{
	int	i;

	if (n_elements == 5)
	{
		i = 4;
		while (--i > 0)
			ft_insertion_sort_a(all);
		if (!ft_is_stack_sorted(all->a))
			ft_sa(all);
		while (all->b)
			ft_pa(all);
	}
	else
	{
		while (all->a)
			ft_insertion_sort_a(all);
		while (all->b)
			ft_pa(all);
	}
}

void	ft_ps_big(t_all *all, int n_elements)
{
	int	chunks_length;
	int	i;
	int	min;
	int chunks;

	if (n_elements >= 50 && n_elements < 100)
		chunks = 4;
	else if (n_elements >= 100 && n_elements < 200)
		chunks = 6;
	else if (n_elements >= 200 && n_elements < 325)
		chunks = 8;
	else if (n_elements >= 325 && n_elements < 450)
		chunks = 10;
	else
		chunks = 13;
	min = ft_list_smallest_value(all->a);
	chunks_length = ft_get_chunk_length(all, min, chunks);
	i = -1;
	while (++i < chunks -1 )
		ft_quick_sort_stack_a(all, min + chunks_length * (i + 1));
	while (all->a)
		ft_pb(all);
	while (all->b)
		ft_insertion_sort_b(all);
}

int	ft_get_chunk_length(t_all *all, int min, int chunks)
{
	int	chunks_length;
	int max;

	max = ft_list_greatest_value(all->a);
	if (max < 0 && min < 0)
		chunks_length = (min - max) / chunks;
	if (max > 0 && min > 0)
		chunks_length = (max - min) / chunks;
	else
		chunks_length = ((min * -1) + max) / chunks;
	return (chunks_length);
}
