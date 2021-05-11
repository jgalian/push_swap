#include "header.h"

// valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./push_swap

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
		ft_error(1);
	all->a = NULL;
	all->b = NULL;
	ft_set_initial_stack(&all->a, argv);
	n_elements = ft_list_lenght(all->a);
	if (n_elements <= 5)
		ft_ps_5(all);
	if (n_elements <= 100)
		ft_ps_100(all);
	else
		ft_ps_500(all);
	ft_clean_up(all);
	return (0);
}

void	ft_ps_5(t_all *all)
{
	int	i;

	i = 4;
	while (--i > 0)
		ft_insertion_sort_100(all);
	if (!ft_is_stack_sorted(all->a))
		ft_sa(all);
	while (all->b)
		ft_pa(all);
}

void	ft_ps_100(t_all *all)
{
	int	average;

	while (all->a->prev && !ft_is_stack_sorted(all->a))
	{
		average = ft_list_values_average(all->a);
		ft_quick_sort_stack_a(all, average);
	}
	while (all->b && !ft_is_stack_sorted(all->b))
	{
		average = ft_list_values_average(all->b);
		ft_quick_sort_stack_b(all, average);
	}
	while (all->a && !ft_is_stack_sorted(all->a))
		ft_insertion_sort_100(all);
	while (all->b)
		ft_pa(all);
}

void	ft_ps_500(t_all *all)
{
	int	average;

	while (all->a->prev && !ft_is_stack_sorted(all->a))
	{
		average = ft_list_values_average(all->a);
		ft_quick_sort_stack_a(all, average);
	}
	while (all->b && !ft_is_stack_sorted(all->b))
	{
		average = ft_list_values_average(all->b);
		ft_quick_sort_stack_b(all, average);
	}
	while (all->a)
		ft_insertion_sort_500_a(all);
	while (all->b->value != ft_list_greatest_value(all->b))
		ft_rrb(all);
	while (all->b)
		ft_pa(all);
	if (all->a->value > all->a->prev->value)
		ft_sa(all);
}
