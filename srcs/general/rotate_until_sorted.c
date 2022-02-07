/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_until_sorted.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:38:31 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/07 14:13:43 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rotate_until_sorted.h"

static int	get_best_distance_of(t_stack *stack, int elem);
static void	rotate_n_times(t_stacks *stacks, int n);

void	rotate_until_sorted(t_stacks *stacks)
{
	int		min;
	t_list	*cur;
	int		distance;

	min = 2147483647;
	cur = stacks->stack_a->lstpp->begin;
	while (cur)
	{
		if (*(int *)cur->content < min)
			min = *(int *)cur->content;
		cur = cur->next;
	}
	distance = get_best_distance_of(stacks->stack_a, min);
	rotate_n_times(stacks, distance);
}

static int	get_best_distance_of(t_stack *stack, int elem)
{
	int	distances[2];	

	get_double_distance_of(stack, elem, distances);
	if (ft_abs(distances[0]) < ft_abs(distances[1]))
		return (distances[0]);
	else
		return (distances[1]);
}

static void	rotate_n_times(t_stacks *stacks, int n)
{
	int	i;

	i = 0;
	while (i < ft_abs(n))
	{
		if (n < 0)
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
