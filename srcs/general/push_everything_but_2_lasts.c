/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_everything_but_2_last.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:55:34 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/03 15:56:38 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_everything_but_2_lasts.h"

static int	get_max(t_list *lst);
static int	has_more_than_3_elems(t_stack *stack);

void	push_everything_but_2_lasts(t_stacks *stacks)
{
	int	max;

	max = get_max(stacks->stack_a->lstpp->begin);
	while (has_more_than_3_elems(stacks->stack_a))
	{
		if (*(int *)stacks->stack_a->lstpp->begin->content == max)
		{
			ra(stacks);
			write(1, "ra\n", 3);
		}
		else
		{
			pb(stacks);
			write(1, "pb\n", 3);
		}
	}
}

static int	get_max(t_list *lst)
{
	int		max;
	t_list	*cur;

	cur = lst;
	max = *(int *) cur->content;
	cur = cur->next;
	while (cur)
	{
		if (*(int *)cur->content > max)
			max = *(int *)cur->content;
		cur = cur->next;
	}
	return (max);
}

static int	has_more_than_3_elems(t_stack *stack)
{
	return (stack->lstpp->begin && stack->lstpp->begin->next
		&& stack->lstpp->begin->next->next);
}
