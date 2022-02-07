/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_to_A_sorted_way.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:08:50 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/07 13:46:58 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_back_to_A_sorted_way.h"

static int	to_relative_distance(int dist, int lst_size);
static int	get_cost(t_stacks *stacks, int elems[2]);
static int	ft_max(int a, int b);
static int	get_upper_bound(t_stacks *stacks, int elem);
static int	ft_min(int a, int b);
int	ft_abs(int nbr);
void	get_double_distance_of(t_stack *stack, int elem, int distances[2]);
static void	bring_to_the_top(t_stacks *stacks, int elems[2]);
static void	push_next_elem_to_A(t_stacks *stacks);
static void	get_closest_elems(t_stacks *stacks, int elems[2]);
//static int	*get_upper_bounds(t_stacks *stacks);

# include <stdio.h>
void	print_stacks(t_stacks *stacks);

void	push_back_to_A_sorted_way(t_stacks *stacks)
{
	while (stacks->stack_b->lstpp->begin)
		push_next_elem_to_A(stacks);
}

static void	push_next_elem_to_A(t_stacks *stacks)
{
	int	elems[2];	

	get_closest_elems(stacks, elems);
	bring_to_the_top(stacks, elems);
	pa(stacks);
	write(1, "pa\n", 3);
//	print_stacks(stacks);
}

static void	bring_to_the_top(t_stacks *stacks, int elems[2])
{
	int	rotates[3]; // 0 => commun, 1 => solo
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
	cost = costs[0];
	rotates[0] = ft_max(dist0[0], dist1[0]);
	rotates[1] = 0;
	rotates[2] = 0;
	if (dist0[0] < dist1[0])
		rotates[1] = dist0[0] - dist1[0];
	else
		rotates[2] = dist1[0] - dist0[0];
	while (i < 4)
	{
		if (costs[i] < cost)
		{
			cost = costs[i];
			rotates[0] = 0;
			rotates[1] = 0;
			rotates[2] = 0;
			if (i == 1)
			{
				rotates[1] = dist0[0];
				rotates[2] = dist1[1];
			}
			if (i == 2)
			{
				rotates[1] = dist0[1];
				rotates[2] = dist1[0];
			}
			if (i == 3)
			{
				rotates[0] = ft_min(dist0[1], dist1[1]);
				if (dist0[1] > dist1[1])
					rotates[1] = dist0[1] - dist1[1];
				else
					rotates[2] = dist1[1] - dist0[1];
			}
		}
		i++;
	}
	i = 0;
	while (i < ft_abs(rotates[0]))
	{
		if (rotates[0] < 0)
		{
			rrr(stacks);
			write(1, "rrr\n", 4);
		}
		else
		{
			rr(stacks);
			write(1, "rr\n", 3);
		}
		i++;
	}
	i = 0;
	while (i < ft_abs(rotates[1]))
	{
		if (rotates[1] < 0)
		{
			rra(stacks);
			write(1, "rra\n", 4);
		}
		else
		{
			ra(stacks);
			write(1, "ra\n", 3);
		}
		i++;
	}
	i = 0;
	while (i < ft_abs(rotates[2]))
	{
		if (rotates[2] < 0)
		{
			rrb(stacks);
			write(1, "rrb\n", 4);
		}
		else
		{
			rb(stacks);
			write(1, "rb\n", 3);
		}
		i++;
	}
}

// elems[0] => elem sur la stack A
// elems[1] => elem sur la stack B
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

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

static int	get_upper_bound(t_stacks *stacks, int elem)
{
	t_list	*cur_a;
	int		upper_bound;

	cur_a = stacks->stack_a->lstpp->begin;
	upper_bound = 2147483647;
	while (cur_a)
	{
		if (*(int *)cur_a->content > elem && *(int *)cur_a->content < upper_bound)
			upper_bound = *(int *)cur_a->content;
		cur_a = cur_a->next;
	}
	return (upper_bound);
}

void	get_double_distance_of(t_stack *stack, int elem, int distances[2])
{
	t_list	*cur;
	int		i;

	i = 0;
	cur = stack->lstpp->begin;
	while (cur && *(int *)cur->content != elem)
	{
		i++;
		cur = cur->next;
	}
	distances[1] = i;
//	distances[0] = to_relative_distance(distances[1], ft_lstsize(stack->lstpp->begin));
	(void) to_relative_distance;
	distances[0] = -(ft_lstsize(stack->lstpp->begin) - i);
}

//static int	get_relative_distance_of(t_stack *stack, int elem)
//{
//	t_list	*cur;
//	int		i;
//	int		relative_dist;
//
//	i = 0;
//	cur = stack->lstpp->begin;
//	while (cur && *(int *)cur->content != elem)
//	{
//		i++;
//		cur = cur->next;
//	}
//	relative_dist = to_relative_distance(i, ft_lstsize(stack->lstpp->begin));
//	return (relative_dist);
//}

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
