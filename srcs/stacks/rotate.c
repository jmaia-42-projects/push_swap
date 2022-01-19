/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:27:56 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/19 16:31:27 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

static void	rotate(t_stack *stack);

void	rr(t_stacks *stacks)
{
	ra(stacks);
	rb(stacks);
}

void	ra(t_stacks *stacks)
{
	rotate(stacks->stack_a);
}

void	rb(t_stacks *stacks)
{
	rotate(stacks->stack_b);
}

static void	rotate(t_stack *stack)
{
	t_list	*new_begin;
	t_list	*new_end;

	if (!stack->lstpp->begin || !stack->lstpp->begin->next)
		return ;
	new_begin = stack->lstpp->begin->next;
	new_end = stack->lstpp->begin;
	ft_lstset_next(stack->lstpp->end, stack->lstpp->begin);
	ft_lstbreaklink(new_end, new_begin);
	stack->lstpp->begin = new_begin;
	stack->lstpp->end = new_end;
}
