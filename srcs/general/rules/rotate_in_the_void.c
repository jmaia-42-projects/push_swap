/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_in_the_void.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:21:11 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/31 22:31:21 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

static t_op	how_do_i_rule_these_stacks(t_stacks *stacks);

t_rule	get_rule_default_rotate_in_the_void(void)
{
	return (&how_do_i_rule_these_stacks);
}

static t_op	how_do_i_rule_these_stacks(t_stacks *stacks)
{
	t_op	op;

	(void) stacks;
	op.op = &ra;
	op.op_name = "ra\n";
	return (op);
}