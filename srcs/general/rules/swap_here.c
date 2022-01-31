/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_here.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:02:52 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/31 17:00:03 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

static const char	*how_do_i_rule_these_stacks(t_stacks *stacks);
static int	will_i_rule_this_stack(t_stack *stack);
static int	are_following(int a, int b, int max);

t_rule	get_rule_swap_here(void)
{
	return (&how_do_i_rule_these_stacks);
}

static const char	*how_do_i_rule_these_stacks(t_stacks *stacks)
{
	int	rule_stack_a;
	int	rule_stack_b;

	rule_stack_a = will_i_rule_this_stack(stacks->stack_a);
	rule_stack_b = will_i_rule_this_stack(stacks->stack_b);
	if (rule_stack_a && rule_stack_b)
		return ("ss\n");
	else if (rule_stack_a)
		return ("sa\n");
	else if (rule_stack_b)
		return ("sb\n");
	else
		return (0);
}

static int	will_i_rule_this_stack(t_stack *stack)
{
	if (!stack->lstpp->begin || !stack->lstpp->begin->next)
		return (0);
	return (!are_following(*(int *)stack->lstpp->begin, *(int *)stack->lstpp->begin->next, 0));
}

static int	are_following(int a, int b, int max)
{
	return (b - a == 1 || (a == max && b == 1));
}
