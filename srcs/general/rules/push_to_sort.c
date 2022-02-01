/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:15:25 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/01 11:20:17 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

static t_op	how_do_i_rule_these_stacks(t_stacks *stacks);

t_rule	get_rule_push_to_sort(void)
{
	return (&how_do_i_rule_these_stacks);
}

static t_op	how_do_i_rule_these_stacks(t_stacks *stacks)
{
	t_op	op;
	int		top_a;
	int		top_b;

	op.op = 0;
	if (!stacks->stack_b->lstpp->begin)
		return (op);
	if (stacks->stack_a->lstpp->begin)
		top_a = *(int *)stacks->stack_a->lstpp->begin->content;
	top_b = *(int *)stacks->stack_b->lstpp->begin->content;
	if (!stacks->stack_a->lstpp->begin || top_a == top_b + 1)
	{
		op.op = &pa;
		op.op_name = "pa\n";
	}
	return (op);
}
