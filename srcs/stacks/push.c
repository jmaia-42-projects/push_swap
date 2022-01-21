/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:19:11 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/19 16:31:13 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

static void	push(t_stack *from, t_stack *to);

void	pa(t_stacks *stacks)
{
	push(stacks->stack_b, stacks->stack_a);
}

void	pb(t_stacks *stacks)
{
	push(stacks->stack_a, stacks->stack_b);
}

static void	push(t_stack *from, t_stack *to)
{
	t_list	*pushed_node;

	if (from->lstpp->begin == 0)
		return ;
	pushed_node = from->lstpp->begin;
	from->lstpp->begin = from->lstpp->begin->next;
	ft_lstset_next(pushed_node, to->lstpp->begin);
	to->lstpp->begin = pushed_node;
}
