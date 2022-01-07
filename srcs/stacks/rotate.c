/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:27:56 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/07 13:34:11 by jmaia            ###   ########.fr       */
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
	t_list	**list;
	t_list	*node_1;
	t_list	*node_2;

	list = &stack->list;
	if (*list == 0 || (*list)->next == 0)
		return ;
	node_1 = *list;
	node_2 = node_1->next;
	ft_lstadd_back(list, node_1);
	*list = node_2;
	node_1->next = 0;
}
