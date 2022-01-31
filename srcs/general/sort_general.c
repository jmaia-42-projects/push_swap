/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:02:17 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/31 22:54:47 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_general.h"

static void	apply_rule(t_rule *rules, t_stacks *stacks);

void	print_sort_general(t_stacks *stacks)
{
	t_rule	*rules;

	rules = get_rules();
	while (!is_sorted(stacks))
		apply_rule(rules, stacks);
	free(rules);
}

static void	apply_rule(t_rule *rules, t_stacks *stacks)
{
	int		i;
	t_op	op;

	i = 0;
	op.op = 0;
	while (rules[i] && !op.op)
	{
		op = rules[i](stacks);
		i++;
	}
	if (op.op)
	{
		op.op(stacks);
		ft_putstr_fd(op.op_name, 1);
	}
}
