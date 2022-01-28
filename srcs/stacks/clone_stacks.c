/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:08:06 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/28 18:46:08 by jmaia            ###   ########.fr       */
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
	free(clone->stack_a->lstpp);
	free(clone->stack_b->lstpp);
	clone->stack_a->lstpp = ft_lstppcpy(stacks->stack_a->lstpp);
	clone->stack_b->lstpp = ft_lstppcpy(stacks->stack_b->lstpp);
	clone->stack_a->checksum = stacks->stack_a->checksum;
	clone->stack_b->checksum = stacks->stack_b->checksum;
	return (clone);
}
