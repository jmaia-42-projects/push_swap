/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:05:29 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/19 16:30:25 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

static void	swap(t_stack *stack);

void	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
}

void	sa(t_stacks *stacks)
{
	swap(stacks->stack_a);
}

void	sb(t_stacks *stacks)
{
	swap(stacks->stack_b);
}

static void	swap(t_stack *stack)
{
	t_list	*node_1;
	t_list	*node_2;
	t_list	*node_3;

	if (!stack->lstpp->begin || !stack->lstpp->begin->next)
		return ;
	node_1 = stack->lstpp->begin;
	node_2 = node_1->next;
	node_3 = node_2->next;
	ft_lstset_next(node_2, node_1);
	ft_lstset_next(node_1, node_3);
	stack->lstpp->begin = node_2;
	if (!node_3)
		stack->lstpp->end = node_1;
}
