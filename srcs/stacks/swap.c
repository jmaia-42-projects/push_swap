/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:05:29 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/18 18:07:04 by jmaia            ###   ########.fr       */
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

	if (stack->list == 0 || stack->list->next == 0)
		return ;
	node_1 = stack->list;
	node_2 = node_1->next;
	node_3 = node_2->next;
	stack->list = node_2;
	ft_lstset_next(node_1, node_3);
	ft_lstset_next(node_2, node_1);
}
