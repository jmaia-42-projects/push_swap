/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_to_A_sorted_way.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:08:50 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/03 19:12:24 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_back_to_A_sorted_way.h"

static int	push_next_elem_to_A(t_stacks *stacks);
static int	*get_upper_bounds(t_stacks *stacks);

int	push_back_to_A_sorted_way(t_stacks *stacks)
{
	while (stacks->stack_b->lstpp->begin)
		push_next_elem_to_A(stacks);
}

static int	push_next_elem_to_A(t_stacks *stacks)
{
	
}

static int	*get_upper_bounds(t_stacks *stacks)
{
	int		*upper_bounds;
	int		stack_b_size;
	t_list	*cur_b;
	t_list	*cur_a;
	int		i;

	stack_b_size = ft_lstsize(stacks->stack_b->lstpp->begin);
	upper_bounds = malloc(sizeof(*upper_bounds) * stack_b_size);
	if (!upper_bounds)
		return (0);
	cur_b = stacks->stack_b->lstpp->begin;
	i = 0;
	while (cur_b)
	{
		cur_a = stacks->stack_a->lstpp->begin;
		while (cur_a)
		{
			
			cur_a = cur_a->next;
		}
		cur_b = cur_b->next;
	}
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
