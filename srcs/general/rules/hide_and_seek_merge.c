/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hide_and_seek_merge.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 08:57:29 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/01 10:28:03 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

static t_op	how_do_i_rule_these_stacks(t_stacks *stacks);
static int	will_i_rule_these_stacks(t_stacks *stacks);

t_rule	get_rule_hide_and_seek_merge(void)
{
	return (&how_do_i_rule_these_stacks);
}

static t_op	how_do_i_rule_these_stacks(t_stacks *stacks)
{
	t_op	op;

	op.op = 0;
	if (will_i_rule_these_stacks(stacks))
	{
		op.op = &ra;
		op.op_name = "ra\n";
	}
	return (op);
}

static int	will_i_rule_these_stacks(t_stacks *stacks)
{
	int	next_a;
	int	top_b;
	int	next_b;
	int	are_first_elems_of_b_sorted;

	if (!stacks->stack_a->lstpp->begin || !stacks->stack_a->lstpp->begin->next || !stacks->stack_b->lstpp->begin || !stacks->stack_b->lstpp->begin->next)
		return  (0);
	next_a = *(int *)stacks->stack_a->lstpp->begin->content;
	top_b = *(int *)stacks->stack_b->lstpp->begin->content;
	next_b = *(int *)stacks->stack_b->lstpp->begin->next->content;
	are_first_elems_of_b_sorted = top_b == next_b + 1;
	if (!are_first_elems_of_b_sorted)
		return (0);
	return (next_a == top_b - 1);
}
