/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:39:50 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/19 16:31:37 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

static void	rrotate(t_stack *stack);

void	rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
}

void	rra(t_stacks *stacks)
{
	rrotate(stacks->stack_a);
}

void	rrb(t_stacks *stacks)
{
	rrotate(stacks->stack_b);
}

static void	rrotate(t_stack *stack)
{
	t_list	*new_begin;
	t_list	*new_end;

	if (!stack->lstpp->begin ||!stack->lstpp->begin->next)
		return ;
	new_begin = stack->lstpp->end;
	new_end = stack->lstpp->end->previous;
	ft_lstset_next(stack->lstpp->end, stack->lstpp->begin);
	ft_lstbreaklink(new_end, new_begin);
	stack->lstpp->begin = new_begin;
	stack->lstpp->end = new_end;
}
