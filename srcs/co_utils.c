#include "header.h"

void	ft_error(int i)
{
	if (i == 1)
		write(1, "Error during memory allocation\n", 32);
	if (i == 2)
		write(1, "All arguments should be numeric\n", 33);
	if (i == 3)
		write(1, "All arguments should not be grater than int size\n", 50);
	if (i == 4)
		write(1, "Arguments shouldn't be duplicated\n", 35);
	if (i == 5)
		write(1, "Instruction don’t exist\n", 27);
	exit(-1);
}

void	ft_print_all_lists(t_all *all)
{
	ft_print_list(all->a);
	ft_print_list(all->b);
	write(1, "\n", 1);
}

int		ft_is_stack_sorted_ps(t_all *all)
{
	t_stack	*tmp;

	tmp = all->a;
	while (tmp->previous)
	{
		if (tmp->value < tmp->previous->value)
			tmp = tmp->previous;
		else
			return (FALSE);
	}
	return (TRUE);
}
