/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_to_A_sorted_way.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:08:50 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/07 15:31:45 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_back_to_A_sorted_way.h"

static int	get_cost(t_stacks *stacks, int elems[2]);
static int	get_upper_bound(t_stacks *stacks, int elem);
static void	push_next_elem_to_a(t_stacks *stacks);
static void	get_closest_elems(t_stacks *stacks, int elems[2]);

void	push_back_to_a_sorted_way(t_stacks *stacks)
{
	while (stacks->stack_b->lstpp->begin)
		push_next_elem_to_a(stacks);
}

static void	push_next_elem_to_a(t_stacks *stacks)
{
	int	elems[2];	

	get_closest_elems(stacks, elems);
	bring_to_the_top(stacks, elems);
	pa(stacks);
	write(1, "pa\n", 3);
}

static void	get_closest_elems(t_stacks *stacks, int elems[2])
{
	t_list	*cur;
	int		min_cost;
	int		cur_cost;
	int		cur_elems[2];

	cur = stacks->stack_b->lstpp->begin;
	elems[0] = 2147483647;
	elems[1] = 2147483647;
	min_cost = 2147483647;
	while (cur)
	{
		cur_elems[0] = get_upper_bound(stacks, *(int *)cur->content);
		cur_elems[1] = *(int *)cur->content;
		cur_cost = get_cost(stacks, cur_elems);
		if (cur_cost < min_cost)
		{
			min_cost = cur_cost;
			elems[0] = cur_elems[0];
			elems[1] = cur_elems[1];
		}
		cur = cur->next;
	}
}

static int	get_cost(t_stacks *stacks, int elems[2])
{
	int	dist0[2];
	int	dist1[2];
	int	cost;
	int	costs[4];
	int	i;

	get_double_distance_of(stacks->stack_a, elems[0], dist0);
	get_double_distance_of(stacks->stack_b, elems[1], dist1);
	costs[0] = ft_max(-dist0[0], -dist1[0]);
	costs[1] = -dist0[0] + dist1[1];
	costs[2] = dist0[1] - dist1[0];
	costs[3] = ft_max(dist0[1], dist1[1]);
	i = 1;
	cost = ft_abs(costs[0]);
	while (i < 4)
	{
		if (costs[i] < cost)
			cost = ft_abs(costs[i]);
		i++;
	}
	return (ft_abs(cost));
}

static int	get_upper_bound(t_stacks *stacks, int elem)
{
	t_list	*cur_a;
	int		upper_bound;

	cur_a = stacks->stack_a->lstpp->begin;
	upper_bound = 2147483647;
	while (cur_a)
	{
		if (*(int *)cur_a->content > elem
			&& *(int *)cur_a->content < upper_bound)
			upper_bound = *(int *)cur_a->content;
		cur_a = cur_a->next;
	}
	return (upper_bound);
}
