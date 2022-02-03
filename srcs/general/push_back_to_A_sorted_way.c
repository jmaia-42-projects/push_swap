/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_to_A_sorted_way.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:08:50 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/03 23:00:19 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_back_to_A_sorted_way.h"

static int	push_next_elem_to_A(t_stacks *stacks);
//static int	*get_upper_bounds(t_stacks *stacks);

int	push_back_to_A_sorted_way(t_stacks *stacks)
{
	while (stacks->stack_b->lstpp->begin)
		push_next_elem_to_A(stacks);
}

static int	push_next_elem_to_A(t_stacks *stacks)
{
	int	elems[2];	

	get_closest_elems(stacks, elems);
	bring_to_the_top(stacks, elems);
}

static void	bring_to_the_top(t_stacks *stacks, int elems[2])
{
	int	dist0;
	int	dist1;

	dist0 = get_relative_distance_of(elems[0]);
	dist1 = get_relative_distance_of(elems[1]);

}

// elems[0] => elem sur la stack A
// elems[1] => elem sur la stack B
static void	get_closest_elems(t_stacks *stacks, int elems[2])
{
	t_list	*cur;
	int		upper_bound;
	int		min_cost;
	int		cur_cost;

	cur = stacks->stack_b->lstpp->begin;
	elems[0] = 2147483647;
	elems[1] = 2147483647;
	min_cost = 2147483647;
	while (cur)
	{
		upper_bound = get_upper_bound(stacks, *(int *)cur->content);
		// Pas possible, faut check les 2 directions voir si ça va au même endoit et tout
		//cur_cost = get_cost(stacks->stack_b, *(int *)cur->content) + get_cost(stacks->stack_a, upper_bound);
		if (cur_cost < min_cost)
		{
			min_cost = cur_cost;
			elems[0] = upper_bound;
			elems[1] = *(int *)cur->content;
		}
		cur = cur->next;
	}
}

//static int	*get_upper_bounds(t_stacks *stacks)
//{
//	int		*upper_bounds;
//	int		stack_b_size;
//	t_list	*cur_b;
//	t_list	*cur_a;
//	int		i;
//
//	stack_b_size = ft_lstsize(stacks->stack_b->lstpp->begin);
//	upper_bounds = malloc(sizeof(*upper_bounds) * stack_b_size);
//	if (!upper_bounds)
//		return (0);
//	cur_b = stacks->stack_b->lstpp->begin;
//	i = 0;
//	while (cur_b)
//	{
//		cur_a = stacks->stack_a->lstpp->begin;
//		while (cur_a)
//		{
//			
//			cur_a = cur_a->next;
//		}
//		cur_b = cur_b->next;
//	}
//}

static int	get_cost(t_stacks *stacks, int elems[2])
{
	int	dist0[2];
	int	dist1[2];

	// Check ton cahier, il faut avoir les distances dans les 4 sens
	// Après, on voit ce qui rend le mieux
	dist0 = get_double_distance_of(stacks->stack_a, elems[0]);
	dist1 = get_double_distance_of(stacks->stack_b, elems[1]);
}

static int	*get_upper_bound(t_stacks *stacks, int elem)
{
	t_list	*cur_a;
	int		upper_bound;

	cur_a = stacks->stack_a->lstpp->begin;
	upper_bound = elem;
	while (cur_a)
	{
		if (*(int *)cur_a->content > elem && elem < upper_bound)
			upper_bound = elem;
		cur_a = cur_a->next;
	}
	return (upper_bound);
}

static void	get_double_distance_of(t_stack *stack, int elem, int distances[2])
{
	t_list	*cur;
	int		i;
	int		relative_dist;

	i = 0;
	cur = stack->lstpp->begin;
	while (cur && *(int *)cur->content != elem)
	{
		i++;
		cur = cur->next;
	}
	distance[0] = i;
	distance[1] = to_relative_distance(i, ft_lstsize(stack->lstpp->begin));
}

static int	get_relative_distance_of(t_stack *stack, int elem)
{
	t_list	*cur;
	int		i;
	int		relative_dist;

	i = 0;
	cur = stack->lstpp->begin;
	while (cur && *(int *)cur->content != elem)
	{
		i++;
		cur = cur->next;
	}
	relative_dist = to_relative_distance(i, ft_lstsize(stack->lstpp->begin));
	return (relative_dist);
}

static int	to_relative_distance(int dist, int lst_size)
{
	int	reverse_dist;
	int	sign;

	sign = 1;
	if (dist < 0)
	{
		dist = -dist;
		sign = -1;
	}
	reverse_dist = lst_size - dist;
	if (dist < reverse_dist)
		return (dist * sign);
	return (reverse_dist * -sign);
}
