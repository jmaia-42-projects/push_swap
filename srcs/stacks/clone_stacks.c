/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:08:06 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/18 14:48:24 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

t_stacks	*clone_stacks(t_stacks *stacks)
{	
	t_stacks	*clone;

	clone = malloc(sizeof(*clone));
	if (!clone)
		return (0);
	clone->stack_a = get_stack();
	clone->stack_b = get_stack();
	if (!clone->stack_a || !clone->stack_b)
	{
		free_stacks(clone, 0);
		return (0);
	}
	clone->stack_a->list = ft_lstcpy(stacks->stack_a->list);
	clone->stack_b->list = ft_lstcpy(stacks->stack_b->list);
	return (clone);
}
