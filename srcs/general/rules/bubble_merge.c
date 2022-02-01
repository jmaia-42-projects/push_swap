/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_merge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 08:45:43 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/01 08:57:10 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

static t_op	how_do_i_rule_these_stacks(t_stacks *stacks);

t_rule	get_rule_bubble_merge(void)
{
	return (&how_do_i_rule_these_stacks);
}

static t_op	how_do_i_rule_these_stacks(t_stacks *stacks)
{
	t_op	op;
	int		top_a;
	int		top_b;
	int		next_a;

	op.op = 0;
	if (!stacks->stack_a->lstpp->begin || !stacks->stack_a->lstpp->begin->next
			|| !stacks->stack_b->lstpp->begin)
		return (op);
	top_a = *(int *)stacks->stack_a->lstpp->begin->content;
	top_b = *(int *)stacks->stack_b->lstpp->begin->content;
	next_a = *(int *)stacks->stack_a->lstpp->begin->next->content;
	if (top_b == top_a + 1 && next_a == top_a + 2)
	{
		op.op = &pa;
		op.op_name = "pa\n";
	}
	return (op);
}
