/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:19:11 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/06 12:27:39 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

static void	push(t_list **from, t_list **to);

void		pa(t_stacks *stacks)
{
	push(&stacks->stack_b, &stacks->stack_a);
}

void		pb(t_stacks *stacks)
{
	push(&stacks->stack_a, &stacks->stack_b);
}

static void	push(t_list **from, t_list **to)
{
	t_list	*pushed_node;

	if (*from == 0)
		return ;
	pushed_node = *from;
	*from = (*from)->next;
	pushed_node->next = *to;
	*to = pushed_node;
}
