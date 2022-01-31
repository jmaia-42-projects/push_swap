/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 22:26:24 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/31 22:34:23 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_sorted.h"

int	is_sorted(t_stacks *stacks)
{
	t_list	*sorted_stack;

	if (stacks->stack_b->lstpp->begin)
		return (0);
	sorted_stack = ft_lstsort(stacks->stack_a->lstpp->begin, &intcmp);
	if (!sorted_stack)
		return (0);
	return (ft_lstequals(stacks->stack_a->lstpp->begin, sorted_stack));
}
