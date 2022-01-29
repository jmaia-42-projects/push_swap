/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_series_strength.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:57:27 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/29 17:25:53 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_series_strength.h"

static int	get_longer_series(t_stack *stack);
static int	are_following(t_stack *stack, t_list *node1, t_list *node2);

int	get_series_strength(t_stacks *stacks)
{
	int	strength;

	strength = get_longer_series(stacks->stack_a);
	return (strength);
}

static int	get_longer_series(t_stack *stack)
{
	int		max_len;
	int		cur_len;
	t_list	*cur;
	t_list	*fake_cur_next;

	max_len = 1;
	cur_len = 1;
	cur = stack->lstpp->begin;
	while (cur)
	{
		if (cur->next)
			fake_cur_next = cur->next;
		else
			fake_cur_next = stack->lstpp->begin;
		if (are_following(stack, cur, fake_cur_next))
			cur_len++;
		else
			cur_len = 1;
		if (max_len < cur_len)
			max_len = cur_len;
		cur = cur->next;
	}
	return (max_len);
}

static int	are_following(t_stack *stack, t_list *node1, t_list *node2)
{
	int	are_really_following;
	int	are_end_start_following;

	are_really_following = *(int *)node2->content == *(int *)node1->content + 1;
	are_end_start_following = *(int *)node1->content == ft_lstsize(stack->lstpp->begin) && *(int *)node2->content == 1;
	return (are_really_following || are_end_start_following);
}
