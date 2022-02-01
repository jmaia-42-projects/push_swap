/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_here.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:02:52 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/01 08:32:48 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

static t_op	how_do_i_rule_these_stacks(t_stacks *stacks);
static int	will_i_rule_this_stack(t_stack *stack, int max);
static int	are_following(int a, int b, int max);
static int	are_neighbours(int a, int b, int max);
static int	are_sorted(int a, int b, int max);

t_rule	get_rule_swap_here(void)
{
	return (&how_do_i_rule_these_stacks);
}

static t_op	how_do_i_rule_these_stacks(t_stacks *stacks) {
	int		rule_stack_a;
	int		rule_stack_b;
	t_op	op;
	int		max;

	op.op = 0;
	max = get_max(stacks);
	rule_stack_a = will_i_rule_this_stack(stacks->stack_a, max);
	rule_stack_b = will_i_rule_this_stack(stacks->stack_b, max);
	if (rule_stack_a && rule_stack_b)
	{
		op.op_name = "ss\n";
		op.op = &ss;
	}
	else if (rule_stack_a)
	{
		op.op_name = "sa\n";
		op.op = &sa;
	}
	else if (rule_stack_b)
	{
		op.op_name = "sb\n";
		op.op = &sb;
	}
	return (op);
}

static int	will_i_rule_this_stack(t_stack *stack, int max)
{
	int	a;
	int	b;

	if (!stack->lstpp->begin || !stack->lstpp->begin->next)
		return (0);
	 a = *(int *)stack->lstpp->begin->content;
	 b = *(int *)stack->lstpp->begin->next->content;
	(void) are_following;
	(void) are_neighbours;
	return (!are_sorted(a, b, max));
}

static int	are_following(int a, int b, int max)
{
	return (b - a == 1 || (a == max && b == 1));
}

static int	are_neighbours(int a, int b, int max)
{
	int	diff;
	int	are_true_neighbours;
	int	are_start_end_neighbours;

	diff = b - a;
	are_true_neighbours = diff == -1 || diff == 1;
	are_start_end_neighbours = (a == max && b == 1) || (a == 1 && b == max);
	return (are_true_neighbours || are_start_end_neighbours);
}

static int	are_sorted(int a, int b, int max)
{
	return (a < b || (a == max && b == 1));
}
