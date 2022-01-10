/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:36:34 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/10 16:38:01 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

t_stack	*get_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(*stack));
	if (!stack)
		return (0);
	stack->list = 0;
	return (stack);
}
