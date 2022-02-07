/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_until_sorted.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:38:31 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/04 14:01:51 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rotate_until_sorted.h"

// A MODIFIER, LES FONCTIONS SONT DANS UN AUTRE FICHIER
int	get_best_distance_of(t_stack *stack, int elem);
int	ft_abs(int nbr);
# include <unistd.h>
void	get_double_distance_of(t_stack *stack, int elem, int distances[2]);

void	rotate_until_sorted(t_stacks *stacks)
{
	int		min;
	t_list	*cur;
	int		distance;
	int		i;

	min = 2147483647;
	cur = stacks->stack_a->lstpp->begin;
	while (cur)
	{
		if (*(int *)cur->content < min)
			min = *(int *)cur->content;
		cur = cur->next;
	}
	distance = get_best_distance_of(stacks->stack_a, min);
	i = 0;
	while (i < ft_abs(distance))
	{
		if (distance < 0)
		{
			write(1, "rra\n", 4);
			rra(stacks);
		}
		else
		{
			write(1, "ra\n", 3);
			ra(stacks);
		}
		i++;
	}
}

int	get_best_distance_of(t_stack *stack, int elem)
{
	int	distances[2];	

	get_double_distance_of(stack, elem, distances);
	if (ft_abs(distances[0]) < ft_abs(distances[1]))
		return (distances[0]);
	else
		return (distances[1]);
}
