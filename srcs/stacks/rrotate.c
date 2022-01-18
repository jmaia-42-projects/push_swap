/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:39:50 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/18 18:05:46 by jmaia            ###   ########.fr       */
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
	t_list	**list;
	t_list	*last;
	t_list	*new_last;

	list = &stack->list;
	if (*list == 0 || (*list)->next == 0)
		return ;
	last = ft_lstlast(*list);
	new_last = ft_lstprevious(*list, last);
	ft_lstset_next(last, *list);
	*list = last;
	ft_lstset_next(new_last, 0);
}
