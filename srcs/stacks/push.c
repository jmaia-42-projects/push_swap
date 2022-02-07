/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:19:11 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/04 14:29:39 by jmaia            ###   ########.fr       */
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
	if (!from->lstpp->begin)
		from->lstpp->end = 0;
	else
		from->lstpp->begin->previous = 0;
	ft_lstppadd_front(to->lstpp, pushed_node);
}
