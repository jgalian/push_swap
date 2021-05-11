#include "header.h"

/*
** This function prints out the values of all elements in the list
*/

void	ft_print_list(t_stack *head)
{
	t_stack	*current;

	if (!head)
		write(1, "List is empty\n", 15);
	else
	{
		current = head;
		while (current != NULL)
		{
			ft_putnbr_fd(current->value, 1);
			current = current->prev;
		}
		write(1, "\n", 1);
	}
}

void	ft_print_all_lists(t_all *all)
{
	ft_print_list(all->a);
	ft_print_list(all->b);
	write(1, "\n", 1);
}
