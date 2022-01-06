/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:05:29 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/06 14:34:29 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

static void	swap(t_list **stack);

void		ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
}

void		sa(t_stacks *stacks)
{
	swap(&stacks->stack_a);
}

void		sb(t_stacks *stacks)
{
	swap(&stacks->stack_b);
}

static void	swap(t_list **stack)
{
	t_list	*node_1;
	t_list	*node_2;
	t_list	*node_3;

	if (*stack == 0 || (*stack)->next == 0)
		return ;
	node_1 = *stack;
	node_2 = node_1->next;
	node_3 = node_2->next;
	*stack = node_2;
	node_1->next = node_3;
	node_2->next = node_1;
}
