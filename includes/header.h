#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"

# define SHRT_MAX 32767
# define SHRT_MIN -32768
# define BUFFER_SIZE 6

typedef struct s_stack
{
	int				value;
	struct s_stack	*prev;
} 					t_stack;

typedef struct s_all
{
	struct s_stack	*a;
	struct s_stack	*b;
}					t_all;

/*
** push_swap.c
*/
void	ft_ps_5(t_all *all);
void	ft_ps_100(t_all *all);
void	ft_ps_500(t_all *all);

/*
** ps_quick_sort.c
*/
void	ft_quick_sort_stack_a(t_all *all, int average);
void	ft_quick_sort_stack_b(t_all *all, int average);

/*
** ps_insertion_sort
*/
void	ft_insertion_sort_100(t_all *all);
void	ft_insertion_sort_500_a(t_all *all);
void	ft_exec_insert_sort_500_a_biggest(t_all *all, int pos_biggest, \
		int rotations_biggest, int n_elements);
void	ft_exec_insert_sort_500_a_smallest(t_all *all, int pos_smallest, \
		int rotations_smallest, int n_elements);

/*
** ch_checker.c
*/
char	**read_stdin(void);
void	execute_instructions(char *inst, t_all *all);
void	ft_check_if_sorted(t_all *all);

/*
** co_list_management.c
*/
int		ft_list_lenght(t_stack *head);
void	ft_push_top(t_stack **head, int value);
void	ft_del_top(t_stack **head);
int		ft_is_stack_sorted(t_stack *head);

/*
** co_list_management_values_calculations.c
*/
int		ft_list_values_average(t_stack *head);
int		ft_list_values_sum(t_stack *head);

/*
** co_list_management_print.c
*/
void	ft_print_list(t_stack *head);
void	ft_print_all_lists(t_all *all);

/*
** co_list_management_swap_values.c
*/
void	ft_swap_a_if_bigger(t_all *all);
void	ft_swap_b_if_bigger(t_all *all);
void	ft_swap_a_if_smaller(t_all *all);
void	ft_swap_b_if_smaller(t_all *all);

/*
** co_list_management_locate_value.c
*/
int		ft_list_smallest_value(t_stack *head);
int		ft_list_greatest_value(t_stack *head);
int		ft_list_greatest_value_position(t_stack *head);
int		ft_list_smallest_value_position(t_stack *head);

/*
** co_list_management_locate_value_2.c
*/
int		ft_found_equal_or_smaller(t_stack *head, int num);
int		ft_found_equal_or_bigger(t_stack *head, int num);

/*
** co_operation_push.c
*/
void	ft_pa(t_all *all);
void	ft_pb(t_all *all);

/*
** co_operation_reverse_rotate.c
*/
void	ft_reverse_rotate(t_stack **head);
void	ft_rra(t_all *all);
void	ft_rrb(t_all *all);
void	ft_rrr(t_all *all);

/*
** co_operation_rotate.c
*/
void	ft_rotate(t_stack **head);
void	ft_ra(t_all *all);
void	ft_rb(t_all *all);
void	ft_rr(t_all *all);

/*
** co_operation_swap.c
*/
void	ft_sa(t_all *all);
void	ft_sb(t_all *all);
void	ft_ss(t_all *all);

/*
** co_set_intital_stack.c
*/
void	ft_set_initial_stack(t_stack **head, char **argv);
void	ft_initialize_array(int *array, int num);
int		process_arguments(char **argv, int i);

/*
** co_utils.c
*/
void	ft_error(int i);
void	ft_clean_up(t_all *all);

#endif
