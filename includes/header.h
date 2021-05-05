#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"

# define SHRT_MAX 32767
# define SHRT_MIN -32768
# define BUFFER_SIZE 6

typedef struct		s_stack
{
	int				value;
	struct s_stack	*previous;
}					t_stack;

typedef struct 		s_all
{
	struct s_stack	*a;
	struct s_stack	*b;
}					t_all;

/* push_swap.c */
// void	ft_set_initial_stack(t_stack **head, char **argv);
// int		process_arguments(char **argv, int i);
// void	ft_error(int i);

/* checker.c */
char	**read_stdin(void);
void	execute_instructions(char *inst, t_all *all);
void	is_stack_sorted(t_all *all);

/* list_management.c */
void	ft_push_top(t_stack **head, int value);
void	ft_del_top(t_stack **head);
void	ft_print_list(t_stack *head);
int		ft_peek(t_stack *head);
int		ft_list_lenght(t_stack *head);

/* operation_push.c */
void	ft_pa(t_all *all);
void	ft_pb(t_all *all);

/* operation_reverse_rotate.c */
void	ft_reverse_rotate(t_stack **head);
void	ft_rra(t_all *all);
void	ft_rrb(t_all *all);
void	ft_rrr(t_all *all);

/* operation_rotate.c */
void	ft_rotate(t_stack **head);
void	ft_ra(t_all *all);
void	ft_rb(t_all *all);
void	ft_rr(t_all *all);

/* operation_swap.c */
void	ft_sa(t_all *all);
void	ft_sb(t_all *all);
void	ft_ss(t_all *all);

/* set_intital_stack.c */
void	ft_set_initial_stack(t_stack **head, char **argv);
int		process_arguments(char **argv, int i);

/* utils.c */
void	ft_print_all_lists(t_all *all);
void	ft_error(int i);

/* get_next_line.c */
int		get_next_line(int fd, char **line);
int		check(int fd, int t_read, char **text, char **line);
int		next_line(char **text, char **line);

#endif
