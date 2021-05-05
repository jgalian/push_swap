#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int	ft_isdigit(int c);
int	check_for_argument_errors(int argc, char **argv);

/*
** This function gets two numbers as argunments. The first one would be the
** number or random elements it will return, and the second one would be the
** range between those random numbers will be generated. This range will
** include positive and negative numbers. As the function rand() only returns
** positive numbers, the formula (two times range minus range) is used to get
** positive and negative numbers. Function uses atoi() to get the strings
** passed as arguments converted to int.
*/

int	main(int argc, char **argv)
{
	time_t	t;
	int		n;
	int 	i;
	int		range;

	if (check_for_argument_errors(argc, argv))
		return (1);
	srand((unsigned) time(&t));
	range = atoi(argv[2]);
	n = atoi(argv[1]);
	while (n-- > 0)
	{
		i = rand() % (range * 2);
		printf("%i ", i - range);
	}
	printf("\n");
	return (0);
}

int	check_for_argument_errors(int argc, char **argv)
{
	int i;

	if (argc < 2 || argc > 3)
	{
		write(2, "This program requires one or two arguments\n", 44);
		return (1);
	}
	i = -1;
	while (argv[1][++i])
	{
		if (!ft_isdigit(argv[1][i]))
		{
			write(2, "First argument should be numeric\n", 34);
			return (1);
		}
	}
	i = -1;
	while (argv[2][++i])
	{
		if (!ft_isdigit(argv[2][i]))
		{
			write(2, "Second argument should be numeric\n", 35);
			return (1);
		}
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}


