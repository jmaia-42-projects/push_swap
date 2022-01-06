/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:27:56 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/06 12:57:47 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

static void	rotate(t_list **stack);

void		rr(t_stacks *stacks)
{
	ra(stacks);
	rb(stacks);
}

void		ra(t_stacks *stacks)
{
	rotate(&stacks->stack_a);
}

void		rb(t_stacks *stacks)
{
	rotate(&stacks->stack_b);
}

static void	rotate(t_list **stack)
{
	t_list	*node_1;
	t_list	*node_2;

	if (*stack == 0 || (*stack)->next == 0)
		return ;
	node_1 = *stack;
	node_2 = node_1->next;
	ft_lstadd_back(stack, node_1);
	*stack = node_2;
	node_1->next = 0;
}
