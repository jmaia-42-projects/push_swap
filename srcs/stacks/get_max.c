/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 08:13:03 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/01 08:14:56 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

int	get_max(t_stacks *stacks)
{
	int	size_stack_a;
	int	size_stack_b;

	size_stack_a = ft_lstsize(stacks->stack_a->lstpp->begin);
	size_stack_b = ft_lstsize(stacks->stack_b->lstpp->begin);
	return (size_stack_a + size_stack_b);
}
