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
	if (i == 6)
		write(1, "Incorrect number of arguments passed to the program\n", 53);
	exit(-1);
}

void	ft_clean_up(t_all *all)
{
	while (all->a)
		ft_del_top(&all->a);
	while (all->b)
		ft_del_top(&all->b);
	free(all);
}
