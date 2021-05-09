#include "header.h"

/* buscar el numero mas bajo de la lista, colocarlo en la primera posicion y mandarlo a b
y asi sucesivamente.
Para ello se necesita saber cuantos elementos hay en la lista, en que posicion esta
y cuantas veces hay que ejecutar ra o rr para mandarlo a la primera posicion */

void	ft_insertion_sort(t_all *all)
{
	int	n_elements;
	int	position;
	int	middle;
	int	rotations;

	position = ft_list_smallest_value_position(all->a);
	n_elements = ft_list_lenght(all->a);
	middle = n_elements / 2;
	if (position <= middle)
		rotations = position;
	else
		rotations = n_elements - position;
	// printf("n_elements: %i\n", n_elements);
	// printf("position: %i\n", position);
	// printf("middle: %i\n", middle);
	// printf("rotations: %i\n", rotations);
	if (position <= middle)
	{
		while (rotations--)
			ft_ra(all);
	}
	else
	{
		while (rotations--)
			ft_rra(all);
	}
	ft_pb(all);
}
