/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:05:15 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/07 13:07:57 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

t_stacks	*get_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(*stacks));
	if (!stacks)
		return (0);
	stacks->stack_a = stack_a;
	stacks->stack_b = stack_b;
	return (stacks);
}
