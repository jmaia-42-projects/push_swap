/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:39:50 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/06 12:55:46 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "stacks.h"

static void	rrotate(t_list **stack);

void		rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
}

void		rra(t_stacks *stacks)
{
	rrotate(&stacks->stack_a);
}

void		rrb(t_stacks *stacks)
{
	rrotate(&stacks->stack_b);
}

static void	rrotate(t_list **stack)
{
	t_list	*last;
	t_list	*new_last;

	if (*stack == 0 || (*stack)->next == 0)
		return ;
	last = ft_lstlast(*stack);
	new_last = ft_lstprevious(*stack, last);
	last->next = *stack;
	*stack = last;
	new_last->next = 0;
}
