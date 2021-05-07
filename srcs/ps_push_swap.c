#include "header.h"

/*
** Push_swap program should receive as argument a list of integers. It has to
** fill the stack A with theese numbers. And then, using a limited type of
** instructions, with help of stack B (empty at the begining), get them sorted
** with the smallest number at the top of stack A. It should use the smallest
** list of instructions possible.
*/

void prueba(t_all *all);

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
	// to do
	//ft_print_all_lists(all);
	while (!ft_is_stack_sorted_ps(all))
	{
		ft_send_all_to_b(all);
		ft_send_all_to_a(all);
	}

	//ft_print_all_lists(all);

}

void	ft_send_all_to_b(t_all *all)
{
	int i;
	int	average;
	int	n_elements;

	n_elements = ft_list_lenght(all->a);
	while (n_elements)
	{
		average = ft_list_values_average(all->a);
		i = 0;
		while (i < n_elements)
		{
			if (all->a->value < average || !all->a->previous)
			{
				ft_pb(all);
				if (all->b && all->b->previous && all->b->value < all->b->previous->value)
					ft_sb(all);
			}
			else
				ft_ra(all);
			//ft_print_all_lists(all);
			//sleep(1);
			i++;
		}
		n_elements = ft_list_lenght(all->a);
	}
}

void	ft_send_all_to_a(t_all *all)
{
	int i;
	int	average;
	int	n_elements;

	n_elements = ft_list_lenght(all->b);
	while (n_elements)
	{
		average = ft_list_values_average(all->b);
		i = 0;
		while (i < n_elements)
		{
			if (all->b->value > average || !all->b->previous)
			{
				ft_pa(all);
				if (all->a && all->a->previous && all->a->value > all->a->previous->value)
					ft_sa(all);
			}
			else
				ft_rb(all);
			//ft_print_all_lists(all);
			//sleep(1);
			i++;
		}
		n_elements = ft_list_lenght(all->b);
	}
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




// ft_list_values_average(all->a);
// 	ft_print_all_lists(all);
// 	ft_pb(all);
// 	ft_print_all_lists(all);
// 	ft_pb(all);
// 	ft_print_all_lists(all);
// 	ft_swap_if_bigger(all, all->b);
// 	ft_print_all_lists(all);



// ft_push_top(&all->b, 5);
	// ft_push_top(&all->b, 7);
	// ft_push_top(&all->b, 9);
	// //print_list(all->b);
	// ft_del_top(&all->b);
	// //print_list(all->b);
	// //printf("Top element: %d\n", n = ft_peek(all->b));
	// ft_sb(all);
	// ft_print_list(all->b);
	// // //t_stack	*head;
	// // int		n;

	// ft_push_top(&all->a, 4);
	// ft_push_top(&all->a, 6);
	// ft_push_top(&all->a, 8);
	// // print_list(all->a);
	// ft_del_top(&all->a);
	// // //ft_del_top(&head);
	// // //ft_del_top(&head);
	// // print_list(all->a);
	// ft_sa(all);
	// ft_print_list(all->a);
	// // //printf("Top element: %d\n", n = ft_peek(all.a));
	// //ft_ss(all);
	// ft_pa(all);
	// ft_del_top(&all->b);
	// ft_print_list(all->b);
	// ft_print_list(all->a);
	// ft_r(&all->a);
	// printf("Number of elements: %i\n", ft_list_lenght(all->a));
	// printf("Number of elements: %i\n", ft_list_lenght(all->b));
	// ft_print_list(all->a);
	// ft_rr(&all->a);
	// ft_print_list(all->a);
