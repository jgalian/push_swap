#include "header.h"

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
