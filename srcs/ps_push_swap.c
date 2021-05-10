#include "header.h"

// valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./push_swap

/*
** Push_swap program should receive as argument a list of integers. It has to
** fill the stack A with theese numbers. And then, using a limited type of
** instructions, with help of stack B (empty at the begining), get them sorted
** with the smallest number at the top of stack A. It should use the smallest
** list of instructions possible.
*/

int		main(int argc, char **argv)
{
	t_all	*all;

	if (argc != 2)
		return (1);
	all = (t_all *)malloc(sizeof(t_all));
	if (!all)
		ft_error(1);
	all->a = NULL;
	all->b = NULL;
	ft_set_initial_stack(&all->a, argv);

	//ft_print_all_lists(all);
	//while (!ft_is_stack_sorted_ps(all))
	//{
		// ft_send_all_to_b(all);
		// ft_send_all_to_a(all);
	//}

	while (all->a->prev && !ft_is_stack_sorted_ps(all->a)) //all))
		ft_quick_sort_a(all);
	while (all->b && !ft_is_stack_sorted_ps(all->b)) //all))
		ft_quick_sort_b(all);

	while (all->a && !ft_is_stack_sorted_ps(all->a)) //all))
	{
		ft_insertion_sort(all);
	}
	while (all->b)
		ft_pa(all);

	//ft_print_all_lists(all);
	ft_clean_up(all);

}


