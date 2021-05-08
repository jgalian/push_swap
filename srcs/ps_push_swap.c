#include "header.h"

// valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./push_swap

/*
** Push_swap program should receive as argument a list of integers. It has to
** fill the stack A with theese numbers. And then, using a limited type of
** instructions, with help of stack B (empty at the begining), get them sorted
** with the smallest number at the top of stack A. It should use the smallest
** list of instructions possible.
*/
void	ft_send_all_to_b_2(t_all *all);
void	ft_send_all_to_a_2(t_all *all);

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
	ft_print_all_lists(all);
	//while (!ft_is_stack_sorted_ps(all))
	//{
		ft_send_all_to_b(all);
		ft_send_all_to_a(all);
		//ft_send_all_to_b_2(all);
		//ft_send_all_to_a_2(all);
	//}

	ft_print_all_lists(all);

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
			//printf("average: %i\n", average);
			ft_swap_a_if_bigger(all);
			// if (all->a && all->a->previous && all->a->value > all->a->previous->value)
			// 	ft_sa(all);
			if (all->a->value <= average || !all->a->previous)
			{
				ft_pb(all);
				if (all->b && all->b->previous && all->b->value < all->b->previous->value)
				{
					if (all->a && all->a->previous && all->a->value > all->a->previous->value)
						ft_ss(all);
					else
				 		ft_sb(all);
				}
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
	int 	i;
	float	average;
	int		n_elements;

	n_elements = ft_list_lenght(all->b);
	while (n_elements)
	{
		average = ft_list_values_average(all->b);
		i = 0;
		while (i < n_elements)
		{
			//printf("average: %i\n", average);
			ft_swap_b_if_smaller(all);
			// if (all->b && all->b->previous && all->b->value < all->b->previous->value)
			// 	ft_sb(all);
			if (all->b->value >= average || !all->b->previous)
			{
				ft_pa(all);
				if (all->a && all->a->previous && all->a->value > all->a->previous->value)
				{
					if (all->b && all->b->previous && all->b->value < all->b->previous->value)
						ft_ss(all);
					else
						ft_sa(all);
				}
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
