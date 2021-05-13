#include "header.h"

/*
** Checker program should receive as argument a list of integers. First, it
** has to get stack A filled with those numbers. Then, it should read from
** standard imput the instructions to get the stack sorted. Once it finishs
** reading, it should execute the instructions over the pile. And finally
** it should checks if stack A is sorted or not and print a OK or KO message.
*/

int	main(int argc, char **argv)
{
	t_all	*all;
	int		i;
	char	**instructions;

	if (argc == 1)
		return (0);
	if (argc > 2)
		ft_error();
	all = (t_all *)malloc(sizeof(t_all));
	if (!all)
		ft_error();
	all->a = NULL;
	all->b = NULL;
	ft_set_initial_stack(&all->a, argv);
	instructions = read_stdin();
	i = -1;
	while (instructions[++i])
		execute_instructions(instructions[i], all);
	ft_check_if_sorted(all);
	instructions = ft_free_matrix(instructions);
	ft_print_all_lists(all);
	ft_clean_up(all);
	return (0);
}

char	**read_stdin(void)
{
	int		ret;
	char	*buf;
	char	*tmp;
	char	*line;
	char	**instructions;

	ret = 1;
	line = strdup("");
	while (ret > 0)
	{
		ret = get_next_line(0, &buf);
		if (ret > 0)
		{
			tmp = ft_strjoin(line, buf);
			buf = ft_free_ptr(buf);
			line = ft_free_ptr(line);
			line = ft_strjoin(tmp, "\n");
			tmp = ft_free_ptr(tmp);
		}
	}
	instructions = ft_split(line, '\n');
	buf = ft_free_ptr(buf);
	line = ft_free_ptr(line);
	return (instructions);
}

void	execute_instructions(char *ins, t_all *all)
{
	if (ins[0] == 's' && ins[1] == 'a' && ins[2] == '\0')
		ft_sa(all);
	else if (ins[0] == 's' && ins[1] == 'b' && ins[2] == '\0')
		ft_sb(all);
	else if (ins[0] == 's' && ins[1] == 's' && ins[2] == '\0')
		ft_ss(all);
	else if (ins[0] == 'p' && ins[1] == 'a' && ins[2] == '\0')
		ft_pa(all);
	else if (ins[0] == 'p' && ins[1] == 'b' && ins[2] == '\0')
		ft_pb(all);
	else if (ins[0] == 'r' && ins[1] == 'a' && ins[2] == '\0')
		ft_ra(all);
	else if (ins[0] == 'r' && ins[1] == 'b' && ins[2] == '\0')
		ft_rb(all);
	else if (ins[0] == 'r' && ins[1] == 'r' && ins[2] == '\0')
		ft_rr(all);
	else if (ins[0] == 'r' && ins[1] == 'r' && ins[2] == 'a' && ins[3] == '\0')
		ft_rra(all);
	else if (ins[0] == 'r' && ins[1] == 'r' && ins[2] == 'b' && ins[3] == '\0')
		ft_rrb(all);
	else if (ins[0] == 'r' && ins[1] == 'r' && ins[2] == 'r' && ins[3] == '\0')
		ft_rrr(all);
	else
		ft_error();
}

void	ft_check_if_sorted(t_all *all)
{
	t_stack	*tmp;

	tmp = all->a;
	while (tmp->prev)
	{
		if (tmp->value < tmp->prev->value)
			tmp = tmp->prev;
		else
		{
			write(1, "KO\n", 3);
			return ;
		}
	}
	write(1, "OK\n", 3);
}
