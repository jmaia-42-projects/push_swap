/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:19:11 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/07 13:34:52 by jmaia            ###   ########.fr       */
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

	if (from->list == 0)
		return ;
	pushed_node = from->list;
	from->list = from->list->next;
	pushed_node->next = to->list;
	to->list = pushed_node;
}
