/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:02:17 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/27 18:40:29 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_general.h"

#include <unistd.h>
static int	get_max(t_stack *stack);
void	print_stacks(t_stacks *stacks);
static int	is_sorted(t_stacks *stacks);

void	print_sort_general(t_stacks *stacks)
{
	int	max;
	int	count;
	int	count2;
	int	i;

	max = get_max(stacks->stack_a);
	if (is_sorted(stacks))
		return ;
	while (stacks->stack_a->lstpp->begin)
	{
		write(1, "pb\n", 3);
		pb(stacks);
	}
	while (stacks->stack_b->lstpp->begin)
	{
		max = get_max(stacks->stack_b);
		count = 0;
		while (*(int *)stacks->stack_b->lstpp->begin->content != max)
		{
			count++;
			rb(stacks);
		}
		if (count > 0)
		{
			rrb(stacks);
			count2 = 1 - count;
			while (*(int *)stacks->stack_b->lstpp->begin->content != max)
			{
				count2++;
				rrb(stacks);
			}
			i = 0;
			while (i < count)
			{
				rrb(stacks);
				i++;
			}
			i = 0;
			while (i < count && i < count2)
			{
				if (count < count2)
				{
					write(1, "rb\n", 3);
					rb(stacks);
				}
				else
				{
					write(1, "rrb\n", 4);
					rrb(stacks);
				}
				print_stacks(stacks);
				i++;
			}
		}
		pa(stacks);
		write(1, "pa\n", 3);
		print_stacks(stacks);
	}
}

static int	is_sorted(t_stacks *stacks)
{
	t_list	*cur;

	if (stacks->stack_b->lstpp->begin)
		return (0);
	cur = stacks->stack_a->lstpp->begin;
	while (cur)
	{
		if (cur->next && *(int *)cur->content > *(int *)cur->next->content)
			return (0);
		cur = cur->next;
	}
	return (1);
}

static int	get_max(t_stack *stack)
{
	t_list	*cur;
	int		max;

	cur = stack->lstpp->begin;
	max = *(int *)stack->lstpp->begin->content;
	while (cur)
	{
		if (*(int *)cur->content > max)
			max = *(int *)cur->content;
		cur = cur->next;
	}
	return (max);
}
